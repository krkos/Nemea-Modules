/************* THIS IS AUTOMATICALLY GENERATED FILE, DO NOT EDIT *************/
// Tables are indexed by field ID
#include "fields.h"

char *ur_field_names_static[] = {
   "DST_IP",
   "LAN_IP",
   "RTR_IP",
   "SRC_IP",
   "WAN_IP",
   "TIME_FIRST",
   "TIME_LAST",
   "DST_PORT",
   "LAN_PORT",
   "RTR_PORT",
   "SRC_PORT",
   "WAN_PORT",
   "DIRECTION",
   "PROTOCOL",
};
short ur_field_sizes_static[] = {
   16, /* DST_IP */
   16, /* LAN_IP */
   16, /* RTR_IP */
   16, /* SRC_IP */
   16, /* WAN_IP */
   8, /* TIME_FIRST */
   8, /* TIME_LAST */
   2, /* DST_PORT */
   2, /* LAN_PORT */
   2, /* RTR_PORT */
   2, /* SRC_PORT */
   2, /* WAN_PORT */
   1, /* DIRECTION */
   1, /* PROTOCOL */
};
ur_field_type_t ur_field_types_static[] = {
   UR_TYPE_IP, /* DST_IP */
   UR_TYPE_IP, /* LAN_IP */
   UR_TYPE_IP, /* RTR_IP */
   UR_TYPE_IP, /* SRC_IP */
   UR_TYPE_IP, /* WAN_IP */
   UR_TYPE_TIME, /* TIME_FIRST */
   UR_TYPE_TIME, /* TIME_LAST */
   UR_TYPE_UINT16, /* DST_PORT */
   UR_TYPE_UINT16, /* LAN_PORT */
   UR_TYPE_UINT16, /* RTR_PORT */
   UR_TYPE_UINT16, /* SRC_PORT */
   UR_TYPE_UINT16, /* WAN_PORT */
   UR_TYPE_UINT8, /* DIRECTION */
   UR_TYPE_UINT8, /* PROTOCOL */
};
ur_static_field_specs_t UR_FIELD_SPECS_STATIC = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 14};
ur_field_specs_t ur_field_specs = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 14, 14, 14, NULL, UR_UNINITIALIZED};
