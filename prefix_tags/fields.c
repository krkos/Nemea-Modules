/************* THIS IS AUTOMATICALLY GENERATED FILE, DO NOT EDIT *************/
// Tables are indexed by field ID
#include "fields.h"

char *ur_field_names_static[] = {
   "DST_IP",
   "SRC_IP",
   "PREFIX_TAG",
};
short ur_field_sizes_static[] = {
   16, /* DST_IP */
   16, /* SRC_IP */
   4, /* PREFIX_TAG */
};
ur_field_type_t ur_field_types_static[] = {
   UR_TYPE_IP, /* DST_IP */
   UR_TYPE_IP, /* SRC_IP */
   UR_TYPE_UINT32, /* PREFIX_TAG */
};
ur_static_field_specs_t UR_FIELD_SPECS_STATIC = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 3};
ur_field_specs_t ur_field_specs = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 3, 3, 3, NULL, UR_UNINITIALIZED};
