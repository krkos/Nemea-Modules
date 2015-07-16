/**
 * \file nfdump_reader_test.cpp
 * \brief Special version of nfdump reader for throughput testing - it reads
 *  whole file into memory before sending flows to the output.
 * \author Vaclav Bartos <ibartosv@fit.vutbr.cz>
 * \date 2013
 * \date 2014
 */
/*
 * Copyright (C) 2013,2014 CESNET
 *
 * LICENSE TERMS
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is'', and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */

#include <cstdlib>
#include <time.h>

#include <signal.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <getopt.h>

#include <libtrap/trap.h>
#include <unirec/unirec.h>
#include <libnfdump.h>

using namespace std;


// A struct without meaning with size equal to UniRec records generated by this module.
struct UniRecSpaceholder {
   char x[66];
};

// Struct with information about module
trap_module_info_t *module_info = NULL;

#define MODULE_BASIC_INFO(BASIC) \
  BASIC("Nfdump-reader module","This module reads a given nfdump file and outputs flow records in UniRec format (special version for throughput testing - it reads all records into memory before sending them to TRAP interface).",0,1)

#define MODULE_PARAMS(PARAM)

static int stop = 0;

void signal_handler(int signal)
{
   if (signal == SIGTERM || signal == SIGINT) {
      stop = 1;
      trap_terminate();
   }
}

int main(int argc, char **argv)
{
   int ret;
   nfdump_iter_t iter;
   trap_ifc_spec_t ifc_spec;

   INIT_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)

   // Create UniRec template
   ur_template_t *tmplt = ur_create_template("SRC_IP,DST_IP,SRC_PORT,DST_PORT,PROTOCOL,TIME_FIRST,TIME_LAST,PACKETS,BYTES,TCP_FLAGS");
   //ur_template_t *tmplt = ur_create_template("SRC_IP,DST_IP,SRC_PORT,DST_PORT,PROTOCOL,TIME_FIRST,TIME_LAST,PACKETS,BYTES,TCP_FLAGS,LINK_BIT_FIELD,DIR_BIT_FIELD");

   // Let TRAP library parse command-line arguments and extract its parameters
   ret = trap_parse_params(&argc, argv, &ifc_spec);
   if (ret != TRAP_E_OK) {
      if (ret == TRAP_E_HELP) { // "-h" was found
         trap_print_help(module_info);
         FREE_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)
         return 0;
      }
      fprintf(stderr, "ERROR in parsing of parameters for TRAP: %s\n", trap_last_error_msg);
      FREE_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)
      return 1;
   }

   if (argc != 2) {
      fprintf(stderr, "Wrong number of parameters.\nUsage: %s -i trap-ifc-specifier nfdump-file\n", argv[0]);
      FREE_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)
      trap_finalize();
      return 2;
   }

   ret = nfdump_iter_start(&iter, argv[1], NULL);
   if (ret != 0) {
      fprintf(stderr, "Error when trying to open file \"%s\"\n", argv[1]);
      trap_finalize();
      FREE_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)
      return 3;
   }

   // Initialize TRAP library (create and init all interfaces)
   ret = trap_init(module_info, ifc_spec);
   if (ret != TRAP_E_OK) {
      nfdump_iter_end(&iter);
      fprintf(stderr, "ERROR in TRAP initialization: %s\n", trap_last_error_msg);
      FREE_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)
      return 4;
   }
   trap_free_ifc_spec(ifc_spec); // We don't need ifc_spec anymore

   signal(SIGTERM, signal_handler);
   signal(SIGINT, signal_handler);


   vector<UniRecSpaceholder> records;
   unsigned cnt_rec = 0;
   srand(time(NULL));

   cout << "Loading data from file..." << endl;
   while (1) {
      master_record_t *rec;

      ret = nfdump_iter_next(&iter, &rec);
      if (ret != 0) {
         if (ret == NFDUMP_EOF) { // no more records
            break;
         }
         fprintf(stderr, "Error during reading file (%i).\n", ret);
         nfdump_iter_end(&iter);
         trap_finalize();
         FREE_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)
         return 3;
      }

      // Allocate new UniRec and put it into records vector
      records.push_back(UniRecSpaceholder());
      void *rec2 = (void*)&records.back();

      ++cnt_rec;

      // Copy data from master_record_t to UniRec record
      if (rec->flags & 0x01) { // IPv6
         uint64_t tmp_ip_v6_addr;
         // Swap IPv6 halves
         tmp_ip_v6_addr = rec->ip_union._v6.srcaddr[0];
         rec->ip_union._v6.srcaddr[0] = rec->ip_union._v6.srcaddr[1];
         rec->ip_union._v6.srcaddr[1] = tmp_ip_v6_addr;
         tmp_ip_v6_addr = rec->ip_union._v6.dstaddr[0];
         rec->ip_union._v6.dstaddr[0] = rec->ip_union._v6.dstaddr[1];
         rec->ip_union._v6.dstaddr[1] = tmp_ip_v6_addr;

         ur_set(tmplt, rec2, UR_SRC_IP, ip_from_16_bytes_le((char *)rec->ip_union._v6.srcaddr));
         ur_set(tmplt, rec2, UR_DST_IP, ip_from_16_bytes_le((char *)rec->ip_union._v6.dstaddr));
      }
      else { // IPv4
         ur_set(tmplt, rec2, UR_SRC_IP, ip_from_4_bytes_le((char *)&rec->ip_union._v4.srcaddr));
         ur_set(tmplt, rec2, UR_DST_IP, ip_from_4_bytes_le((char *)&rec->ip_union._v4.dstaddr));

      }
      ur_set(tmplt, rec2, UR_SRC_PORT, rec->srcport);
      ur_set(tmplt, rec2, UR_DST_PORT, rec->dstport);
      ur_set(tmplt, rec2, UR_PROTOCOL, rec->prot);
      ur_set(tmplt, rec2, UR_TCP_FLAGS, rec->tcp_flags);
      ur_set(tmplt, rec2, UR_PACKETS, rec->dPkts);
      ur_set(tmplt, rec2, UR_BYTES, rec->dOctets);
      uint64_t first = ur_time_from_sec_msec(rec->first, rec->msec_first);
      uint64_t last  = ur_time_from_sec_msec(rec->last, rec->msec_last);
      ur_set(tmplt, rec2, UR_TIME_FIRST, first);
      ur_set(tmplt, rec2, UR_TIME_LAST, last);

      // assign value for link and direction of the flow
      /*if ((counter % (rand() % 50000 + 50000)) == 0) {
          ur_set(tmplt, rec2, UR_LINK_BIT_FIELD, 0x01);
      } else if ((counter % (rand() % 40000 + 1))) {
          ur_set(tmplt, rec2, UR_LINK_BIT_FIELD, 0x02);
      } else {
          ur_set(tmplt, rec2, UR_LINK_BIT_FIELD, 0x04);
      }

      ur_set(tmplt, rec2, UR_DIR_BIT_FIELD, rec->input);
      */

   }

   nfdump_iter_end(&iter);

   cout << "Sending (" << records.size() << ") records..." << endl;

   // Read a record from file, convert to UniRec and send to output ifc
   for (int i = 0; i < records.size() && !stop; i++)
   {
      // Send data to output interface
      trap_send_data(0, &records[i], sizeof(records[i]), TRAP_WAIT);
      //usleep(100);
   }
   cout << "Sending terminating record..." << endl;

   // Send data with zero length to signalize end
   if (!stop)
      trap_send_data(0, &records[0], 1, TRAP_WAIT); // FIXME: zero-length messages doesn't work, send message of length 1

   // Do all necessary cleanup before exiting
   ur_free_template(tmplt);
   trap_finalize();
   FREE_MODULE_INFO_STRUCT(MODULE_BASIC_INFO, MODULE_PARAMS)

   return 0;
}

