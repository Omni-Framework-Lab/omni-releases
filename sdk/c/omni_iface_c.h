#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////
// Typedefs for all functions of the DLL.
///////////////////////////////////////////////////////////////////////

typedef struct Omni_Tree Omni_Tree;
typedef struct Omni_Variable Omni_Variable;

enum Omni_VariableType
{
	OMNI_INT8,
	OMNI_UINT8,
	OMNI_INT16,
	OMNI_UINT16,
	OMNI_INT32,
	OMNI_UINT32,
	OMNI_INT64,
	OMNI_UINT64,
	OMNI_FLOAT,
	OMNI_DOUBLE,
	OMNI_STRING,
};

static const uint32_t OMNI_VARIABLE_MAX_SIZE = 256;

///////////////////////////////////////////////////////////////////////
// The API.
///////////////////////////////////////////////////////////////////////

void omni_init_set_library_path(const char* library_path);
void omni_init_set_instance_id(const char* instance_id);
void omni_init_mode_owner(const char* config_file_path);

Omni_Tree* omni_find_tree(const char* tree_id);
void omni_tree_free(Omni_Tree* tree);

Omni_Variable* omni_find_variable_i8(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_i16(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_i32(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_i64(Omni_Tree* tree, const char* path);

Omni_Variable* omni_find_variable_u8(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_u16(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_u32(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_u64(Omni_Tree* tree, const char* path);

Omni_Variable* omni_find_variable_float(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_double(Omni_Tree* tree, const char* path);
Omni_Variable* omni_find_variable_string(Omni_Tree* tree, const char* path);

void omni_variable_free(Omni_Variable* variable);
Omni_Variable* omni_variable_clone(Omni_Variable* variable);
int omni_variable_has_changed(Omni_Variable* variable);

int8_t omni_read_variable_i8(Omni_Variable* variable);
int16_t omni_read_variable_i16(Omni_Variable* variable);
int32_t omni_read_variable_i32(Omni_Variable* variable);
int64_t omni_read_variable_i64(Omni_Variable* variable);

uint8_t omni_read_variable_u8(Omni_Variable* variable);
uint16_t omni_read_variable_u16(Omni_Variable* variable);
uint32_t omni_read_variable_u32(Omni_Variable* variable);
uint64_t omni_read_variable_u64(Omni_Variable* variable);

float omni_read_variable_float(Omni_Variable* variable);
double omni_read_variable_double(Omni_Variable* variable);
void omni_read_variable_string(Omni_Variable* variable, char* dst, size_t dst_size);

void omni_write_variable_i8(Omni_Variable* variable, int8_t value);
void omni_write_variable_i16(Omni_Variable* variable, int16_t value);
void omni_write_variable_i32(Omni_Variable* variable, int32_t value);
void omni_write_variable_i64(Omni_Variable* variable, int64_t value);

void omni_write_variable_u8(Omni_Variable* variable, uint8_t value);
void omni_write_variable_u16(Omni_Variable* variable, uint16_t value);
void omni_write_variable_u32(Omni_Variable* variable, uint32_t value);
void omni_write_variable_u64(Omni_Variable* variable, uint64_t value);

void omni_write_variable_float(Omni_Variable* variable, float value);
void omni_write_variable_double(Omni_Variable* variable, double value);
void omni_write_variable_string(Omni_Variable* variable, const char* str, size_t len);

#ifdef __cplusplus
}
#endif