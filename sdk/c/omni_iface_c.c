#include "omni_iface_c.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

//typedef void (*OmniIface_init_t)(int argc, char** argv);

typedef void (*OmniIface_init_set_instance_id_t)(const char* instance_id);
typedef void (*OmniIface_init_mode_owner_t)(const char* config_file_path);

typedef Omni_Tree* (*OmniIface_find_tree_t)(const char* tree_id);
typedef void (*OmniIface_free_tree_t)(Omni_Tree* tree);

typedef Omni_Variable* (*OmniIface_find_variable_i8_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_i16_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_i32_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_i64_t)(Omni_Tree* tree, const char* path);

typedef Omni_Variable* (*OmniIface_find_variable_u8_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_u16_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_u32_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_u64_t)(Omni_Tree* tree, const char* path);

typedef Omni_Variable* (*OmniIface_find_variable_float_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_double_t)(Omni_Tree* tree, const char* path);
typedef Omni_Variable* (*OmniIface_find_variable_string_t)(Omni_Tree* tree, const char* path);

typedef void (*OmniIface_variable_free_t)(Omni_Variable* variable);
typedef Omni_Variable* (*OmniIface_variable_clone_t)(Omni_Variable* variable);
typedef int (*OmniIface_variable_has_changed_t)(Omni_Variable* variable);

typedef int8_t (*OmniIface_read_variable_i8_t)(Omni_Variable* variable);
typedef int16_t (*OmniIface_read_variable_i16_t)(Omni_Variable* variable);
typedef int32_t (*OmniIface_read_variable_i32_t)(Omni_Variable* variable);
typedef int64_t (*OmniIface_read_variable_i64_t)(Omni_Variable* variable);

typedef uint8_t (*OmniIface_read_variable_u8_t)(Omni_Variable* variable);
typedef uint16_t (*OmniIface_read_variable_u16_t)(Omni_Variable* variable);
typedef uint32_t (*OmniIface_read_variable_u32_t)(Omni_Variable* variable);
typedef uint64_t (*OmniIface_read_variable_u64_t)(Omni_Variable* variable);

typedef float (*OmniIface_read_variable_float_t)(Omni_Variable* variable);
typedef double (*OmniIface_read_variable_double_t)(Omni_Variable* variable);
typedef void (*OmniIface_read_variable_string_t)(Omni_Variable* variable, char* dst, unsigned long long dst_size);

typedef void (*OmniIface_write_variable_i8_t)(Omni_Variable* variable, int8_t value);
typedef void (*OmniIface_write_variable_i16_t)(Omni_Variable* variable, int16_t value);
typedef void (*OmniIface_write_variable_i32_t)(Omni_Variable* variable, int32_t value);
typedef void (*OmniIface_write_variable_i64_t)(Omni_Variable* variable, int64_t value);

typedef void (*OmniIface_write_variable_u8_t)(Omni_Variable* variable, uint8_t value);
typedef void (*OmniIface_write_variable_u16_t)(Omni_Variable* variable, uint16_t value);
typedef void (*OmniIface_write_variable_u32_t)(Omni_Variable* variable, uint32_t value);
typedef void (*OmniIface_write_variable_u64_t)(Omni_Variable* variable, uint64_t value);

typedef void (*OmniIface_write_variable_float_t)(Omni_Variable* variable, float value);
typedef void (*OmniIface_write_variable_double_t)(Omni_Variable* variable, double value);
typedef void (*OmniIface_write_variable_string_t)(Omni_Variable* variable, const char* value, size_t len);

struct LoadedDLL
{
	//OmniIface_init_t init;

	OmniIface_init_set_instance_id_t init_set_instance_id;
	OmniIface_init_mode_owner_t init_mode_owner;

	OmniIface_find_tree_t find_tree;
	OmniIface_free_tree_t free_tree;

	OmniIface_find_variable_i8_t find_variable_i8;
	OmniIface_find_variable_i16_t find_variable_i16;
	OmniIface_find_variable_i32_t find_variable_i32;
	OmniIface_find_variable_i64_t find_variable_i64;

	OmniIface_find_variable_u8_t find_variable_u8;
	OmniIface_find_variable_u16_t find_variable_u16;
	OmniIface_find_variable_u32_t find_variable_u32;
	OmniIface_find_variable_u64_t find_variable_u64;

	OmniIface_find_variable_float_t find_variable_float;
	OmniIface_find_variable_double_t find_variable_double;
	OmniIface_find_variable_string_t find_variable_string;

	OmniIface_variable_free_t variable_free;
	OmniIface_variable_clone_t variable_clone;
	OmniIface_variable_has_changed_t variable_has_changed;

	OmniIface_read_variable_i8_t read_variable_i8;
	OmniIface_read_variable_i16_t read_variable_i16;
	OmniIface_read_variable_i32_t read_variable_i32;
	OmniIface_read_variable_i64_t read_variable_i64;

	OmniIface_read_variable_u8_t read_variable_u8;
	OmniIface_read_variable_u16_t read_variable_u16;
	OmniIface_read_variable_u32_t read_variable_u32;
	OmniIface_read_variable_u64_t read_variable_u64;

	OmniIface_read_variable_float_t read_variable_float;
	OmniIface_read_variable_double_t read_variable_double;
	OmniIface_read_variable_string_t read_variable_string;

	OmniIface_write_variable_i8_t write_variable_i8;
	OmniIface_write_variable_i16_t write_variable_i16;
	OmniIface_write_variable_i32_t write_variable_i32;
	OmniIface_write_variable_i64_t write_variable_i64;

	OmniIface_write_variable_u8_t write_variable_u8;
	OmniIface_write_variable_u16_t write_variable_u16;
	OmniIface_write_variable_u32_t write_variable_u32;
	OmniIface_write_variable_u64_t write_variable_u64;

	OmniIface_write_variable_float_t write_variable_float;
	OmniIface_write_variable_double_t write_variable_double;
	OmniIface_write_variable_string_t write_variable_string;
} _iface;

static char load_library_path[256] = "omni_core_iface_c.dll";

/*! Loads the dynamic library and initializes its function references. */
static void omni_iface_init()
{
#ifdef _WIN32
	static HINSTANCE dll = NULL;
	if (!dll)
	{
		dll = LoadLibraryA(load_library_path);
		if (dll)
		{
			//_iface.init = (OmniIface_init_t)GetProcAddress(dll, "omni_init");

			_iface.init_set_instance_id = (OmniIface_init_set_instance_id_t)GetProcAddress(dll, "omni_init_set_instance_id");
			_iface.init_mode_owner = (OmniIface_init_mode_owner_t)GetProcAddress(dll, "omni_init_mode_owner");

			_iface.find_tree = (OmniIface_find_tree_t)GetProcAddress(dll, "omni_find_tree");
			_iface.free_tree = (OmniIface_free_tree_t)GetProcAddress(dll, "omni_tree_free");

			_iface.find_variable_i8 = (OmniIface_find_variable_i8_t)GetProcAddress(dll, "omni_find_variable_i8");
			_iface.find_variable_i16 = (OmniIface_find_variable_i16_t)GetProcAddress(dll, "omni_find_variable_i16");
			_iface.find_variable_i32 = (OmniIface_find_variable_i32_t)GetProcAddress(dll, "omni_find_variable_i32");
			_iface.find_variable_i64 = (OmniIface_find_variable_i64_t)GetProcAddress(dll, "omni_find_variable_i64");

			_iface.find_variable_u8 = (OmniIface_find_variable_u8_t)GetProcAddress(dll, "omni_find_variable_u8");
			_iface.find_variable_u16 = (OmniIface_find_variable_u16_t)GetProcAddress(dll, "omni_find_variable_u16");
			_iface.find_variable_u32 = (OmniIface_find_variable_u32_t)GetProcAddress(dll, "omni_find_variable_u32");
			_iface.find_variable_u64 = (OmniIface_find_variable_u64_t)GetProcAddress(dll, "omni_find_variable_u64");

			_iface.find_variable_float = (OmniIface_find_variable_float_t)GetProcAddress(dll, "omni_find_variable_float");
			_iface.find_variable_double = (OmniIface_find_variable_double_t)GetProcAddress(dll, "omni_find_variable_double");
			_iface.find_variable_string = (OmniIface_find_variable_string_t)GetProcAddress(dll, "omni_find_variable_string");

			_iface.variable_free = (OmniIface_variable_free_t)GetProcAddress(dll, "omni_variable_free");
			_iface.variable_clone = (OmniIface_variable_clone_t)GetProcAddress(dll, "omni_variable_clone");
			_iface.variable_has_changed = (OmniIface_variable_has_changed_t)GetProcAddress(dll, "omni_variable_has_changed");

			_iface.read_variable_i8 = (OmniIface_read_variable_i8_t)GetProcAddress(dll, "omni_read_variable_i8");
			_iface.read_variable_i16 = (OmniIface_read_variable_i16_t)GetProcAddress(dll, "omni_read_variable_i16");
			_iface.read_variable_i32 = (OmniIface_read_variable_i32_t)GetProcAddress(dll, "omni_read_variable_i32");
			_iface.read_variable_i64 = (OmniIface_read_variable_i64_t)GetProcAddress(dll, "omni_read_variable_i64");

			_iface.read_variable_u8 = (OmniIface_read_variable_u8_t)GetProcAddress(dll, "omni_read_variable_u8");
			_iface.read_variable_u16 = (OmniIface_read_variable_u16_t)GetProcAddress(dll, "omni_read_variable_u16");
			_iface.read_variable_u32 = (OmniIface_read_variable_u32_t)GetProcAddress(dll, "omni_read_variable_u32");
			_iface.read_variable_u64 = (OmniIface_read_variable_u64_t)GetProcAddress(dll, "omni_read_variable_u64");

			_iface.read_variable_float = (OmniIface_read_variable_float_t)GetProcAddress(dll, "omni_read_variable_float");
			_iface.read_variable_double = (OmniIface_read_variable_double_t)GetProcAddress(dll, "omni_read_variable_double");
			_iface.read_variable_string = (OmniIface_read_variable_string_t)GetProcAddress(dll, "omni_read_variable_string");

			_iface.write_variable_i8 = (OmniIface_write_variable_i8_t)GetProcAddress(dll, "omni_write_variable_i8");
			_iface.write_variable_i16 = (OmniIface_write_variable_i16_t)GetProcAddress(dll, "omni_write_variable_i16");
			_iface.write_variable_i32 = (OmniIface_write_variable_i32_t)GetProcAddress(dll, "omni_write_variable_i32");
			_iface.write_variable_i64 = (OmniIface_write_variable_i64_t)GetProcAddress(dll, "omni_write_variable_i64");

			_iface.write_variable_u8 = (OmniIface_write_variable_u8_t)GetProcAddress(dll, "omni_write_variable_u8");
			_iface.write_variable_u16 = (OmniIface_write_variable_u16_t)GetProcAddress(dll, "omni_write_variable_u16");
			_iface.write_variable_u32 = (OmniIface_write_variable_u32_t)GetProcAddress(dll, "omni_write_variable_u32");
			_iface.write_variable_u64 = (OmniIface_write_variable_u64_t)GetProcAddress(dll, "omni_write_variable_u64");

			_iface.write_variable_float = (OmniIface_write_variable_float_t)GetProcAddress(dll, "omni_write_variable_float");
			_iface.write_variable_double = (OmniIface_write_variable_double_t)GetProcAddress(dll, "omni_write_variable_double");
			_iface.write_variable_string = (OmniIface_write_variable_string_t)GetProcAddress(dll, "omni_write_variable_string");
		}
		//_iface.init(argc, argv);
	}
#endif
}

void omni_init_set_library_path(const char* library_path)
{
	strcpy(load_library_path, library_path);
}

void omni_init_set_instance_id(const char* instance_id)
{
	omni_iface_init();
	_iface.init_set_instance_id(instance_id);
}

void omni_init_mode_owner(const char* config_file_path)
{
	omni_iface_init();
	_iface.init_mode_owner(config_file_path);
}

Omni_Tree* omni_find_tree(const char* tree_id)
{
	omni_iface_init();
	return _iface.find_tree(tree_id);
}

void omni_tree_free(Omni_Tree* tree)
{
	_iface.free_tree(tree);
}

Omni_Variable* omni_find_variable_i8(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_i8(tree, path);
}

Omni_Variable* omni_find_variable_i16(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_i16(tree, path);
}

Omni_Variable* omni_find_variable_i32(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_i32(tree, path);
}

Omni_Variable* omni_find_variable_i64(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_i64(tree, path);
}

Omni_Variable* omni_find_variable_u8(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_u8(tree, path);
}

Omni_Variable* omni_find_variable_u16(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_u16(tree, path);
}

Omni_Variable* omni_find_variable_u32(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_u32(tree, path);
}

Omni_Variable* omni_find_variable_u64(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_u64(tree, path);
}

Omni_Variable* omni_find_variable_float(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_float(tree, path);
}

Omni_Variable* omni_find_variable_double(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_double(tree, path);
}

Omni_Variable* omni_find_variable_string(Omni_Tree* tree, const char* path)
{
	return _iface.find_variable_string(tree, path);
}

void omni_variable_free(Omni_Variable* variable)
{
	_iface.variable_free(variable);
}

Omni_Variable* omni_variable_clone(Omni_Variable* variable)
{
	return _iface.variable_clone(variable);
}

int omni_variable_has_changed(Omni_Variable* variable)
{
	return _iface.variable_has_changed(variable);
}

int8_t omni_read_variable_i8(Omni_Variable* variable)
{
	return _iface.read_variable_i8(variable);
}

int16_t omni_read_variable_i16(Omni_Variable* variable)
{
	return _iface.read_variable_i16(variable);
}

int32_t omni_read_variable_i32(Omni_Variable* variable)
{
	return _iface.read_variable_i32(variable);
}

int64_t omni_read_variable_i64(Omni_Variable* variable)
{
	return _iface.read_variable_i64(variable);
}

uint8_t omni_read_variable_u8(Omni_Variable* variable)
{
	return _iface.read_variable_u8(variable);
}

uint16_t omni_read_variable_u16(Omni_Variable* variable)
{
	return _iface.read_variable_u16(variable);
}

uint32_t omni_read_variable_u32(Omni_Variable* variable)
{
	return _iface.read_variable_u32(variable);
}

uint64_t omni_read_variable_u64(Omni_Variable* variable)
{
	return _iface.read_variable_u64(variable);
}

float omni_read_variable_float(Omni_Variable* variable)
{
	return _iface.read_variable_float(variable);
}

double omni_read_variable_double(Omni_Variable* variable)
{
	return _iface.read_variable_double(variable);
}

void omni_read_variable_string(Omni_Variable* variable, char* dst, size_t dst_size)
{
	_iface.read_variable_string(variable, dst, dst_size);
}

void omni_write_variable_i8(Omni_Variable* variable, int8_t value)
{
	_iface.write_variable_i8(variable, value);
}

void omni_write_variable_i16(Omni_Variable* variable, int16_t value)
{
	_iface.write_variable_i16(variable, value);
}

void omni_write_variable_i32(Omni_Variable* variable, int32_t value)
{
	_iface.write_variable_i32(variable, value);
}

void omni_write_variable_i64(Omni_Variable* variable, int64_t value)
{
	_iface.write_variable_i64(variable, value);
}

void omni_write_variable_u8(Omni_Variable* variable, uint8_t value)
{
	_iface.write_variable_u8(variable, value);
}

void omni_write_variable_u16(Omni_Variable* variable, uint16_t value)
{
	_iface.write_variable_u16(variable, value);
}

void omni_write_variable_u32(Omni_Variable* variable, uint32_t value)
{
	_iface.write_variable_u32(variable, value);
}

void omni_write_variable_u64(Omni_Variable* variable, uint64_t value)
{
	_iface.write_variable_u64(variable, value);
}

void omni_write_variable_float(Omni_Variable* variable, float value)
{
	_iface.write_variable_float(variable, value);
}

void omni_write_variable_double(Omni_Variable* variable, double value)
{
	_iface.write_variable_double(variable, value);
}

void omni_write_variable_string(Omni_Variable* variable, const char* str, size_t len)
{
	_iface.write_variable_string(variable, str, len);
}

#ifdef __cplusplus
}
#endif