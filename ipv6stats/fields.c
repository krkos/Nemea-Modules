/************* THIS IS AUTOMATICALLY GENERATED FILE, DO NOT EDIT *************/
// Tables are indexed by field ID
#include "fields.h"

char *ur_field_names_static[] = {
   "DST_IP",
   "SRC_IP",
   "BYTES",
   "LINK_BIT_FIELD",
   "TIME_FIRST",
   "TIME_LAST",
   "PACKETS",
   "DST_PORT",
   "SRC_PORT",
   "DIR_BIT_FIELD",
   "IPV6_TUN_TYPE",
   "PROTOCOL",
   "TCP_FLAGS",
   "TOS",
   "TTL",
};
short ur_field_sizes_static[] = {
   16, /* DST_IP */
   16, /* SRC_IP */
   8, /* BYTES */
   8, /* LINK_BIT_FIELD */
   8, /* TIME_FIRST */
   8, /* TIME_LAST */
   4, /* PACKETS */
   2, /* DST_PORT */
   2, /* SRC_PORT */
   1, /* DIR_BIT_FIELD */
   1, /* IPV6_TUN_TYPE */
   1, /* PROTOCOL */
   1, /* TCP_FLAGS */
   1, /* TOS */
   1, /* TTL */
};
ur_field_type_t ur_field_types_static[] = {
   UR_TYPE_IP, /* DST_IP */
   UR_TYPE_IP, /* SRC_IP */
   UR_TYPE_UINT64, /* BYTES */
   UR_TYPE_UINT64, /* LINK_BIT_FIELD */
   UR_TYPE_TIME, /* TIME_FIRST */
   UR_TYPE_TIME, /* TIME_LAST */
   UR_TYPE_UINT32, /* PACKETS */
   UR_TYPE_UINT16, /* DST_PORT */
   UR_TYPE_UINT16, /* SRC_PORT */
   UR_TYPE_UINT8, /* DIR_BIT_FIELD */
   UR_TYPE_UINT8, /* IPV6_TUN_TYPE */
   UR_TYPE_UINT8, /* PROTOCOL */
   UR_TYPE_UINT8, /* TCP_FLAGS */
   UR_TYPE_UINT8, /* TOS */
   UR_TYPE_UINT8, /* TTL */
};
ur_static_field_specs_t UR_FIELD_SPECS_STATIC = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 15};
ur_field_specs_t ur_field_specs = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 15, 15, 15, NULL, UR_UNINITIALIZED};
