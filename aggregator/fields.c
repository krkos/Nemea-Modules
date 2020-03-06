/************* THIS IS AUTOMATICALLY GENERATED FILE, DO NOT EDIT *************/
// Tables are indexed by field ID
#include "fields.h"

char *ur_field_names_static[] = {
   "TIME_FIRST",
   "TIME_LAST",
   "COUNT",
};
short ur_field_sizes_static[] = {
   8, /* TIME_FIRST */
   8, /* TIME_LAST */
   4, /* COUNT */
};
ur_field_type_t ur_field_types_static[] = {
   UR_TYPE_TIME, /* TIME_FIRST */
   UR_TYPE_TIME, /* TIME_LAST */
   UR_TYPE_UINT32, /* COUNT */
};
ur_static_field_specs_t UR_FIELD_SPECS_STATIC = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 3};
ur_field_specs_t ur_field_specs = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 3, 3, 3, NULL, UR_UNINITIALIZED};
