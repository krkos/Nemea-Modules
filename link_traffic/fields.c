/************* THIS IS AUTOMATICALLY GENERATED FILE, DO NOT EDIT *************/
// Tables are indexed by field ID
#include "fields.h"

char *ur_field_names_static[] = {
   "BYTES",
   "LINK_BIT_FIELD",
   "PACKETS",
   "DIR_BIT_FIELD",
};
short ur_field_sizes_static[] = {
   8, /* BYTES */
   8, /* LINK_BIT_FIELD */
   4, /* PACKETS */
   1, /* DIR_BIT_FIELD */
};
ur_field_type_t ur_field_types_static[] = {
   UR_TYPE_UINT64, /* BYTES */
   UR_TYPE_UINT64, /* LINK_BIT_FIELD */
   UR_TYPE_UINT32, /* PACKETS */
   UR_TYPE_UINT8, /* DIR_BIT_FIELD */
};
ur_static_field_specs_t UR_FIELD_SPECS_STATIC = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 4};
ur_field_specs_t ur_field_specs = {ur_field_names_static, ur_field_sizes_static, ur_field_types_static, 4, 4, 4, NULL, UR_UNINITIALIZED};
