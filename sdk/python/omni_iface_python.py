import ctypes

VERSION = "1.0.0"
SHARED_LIBRARY_PATH = "omni_core_iface_c.dll"
IFACE_INSTANCE = None

class Iface:
	def __init__(self):
		self.lib = None
		self._load_library()

	def _load_library(self):
		self.lib = ctypes.cdll.LoadLibrary(SHARED_LIBRARY_PATH)

		### 

		self.lib.omni_find_tree.argtypes = [ctypes.c_char_p]
		self.lib.omni_find_tree.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_i8.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_i8.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_i16.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_i16.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_i32.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_i32.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_i64.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_i64.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_u8.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_u8.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_u16.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_u16.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_u32.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_u32.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_u64.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_u64.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_float.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_float.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_double.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_double.restype  = ctypes.c_void_p

		self.lib.omni_find_variable_string.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_find_variable_string.restype  = ctypes.c_void_p

		### READ

		self.lib.omni_read_variable_i8.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_i8.restype = ctypes.c_int8

		self.lib.omni_read_variable_i16.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_i16.restype = ctypes.c_int16

		self.lib.omni_read_variable_i32.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_i32.restype = ctypes.c_int32

		self.lib.omni_read_variable_i64.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_i64.restype = ctypes.c_int64

		self.lib.omni_read_variable_u8.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_u8.restype = ctypes.c_uint8

		self.lib.omni_read_variable_u16.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_u16.restype = ctypes.c_uint16

		self.lib.omni_read_variable_u32.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_u32.restype = ctypes.c_uint32

		self.lib.omni_read_variable_u64.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_u64.restype = ctypes.c_uint64

		self.lib.omni_read_variable_float.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_float.restype = ctypes.c_float

		self.lib.omni_read_variable_double.argtypes = [ctypes.c_void_p]
		self.lib.omni_read_variable_double.restype = ctypes.c_double

		self.lib.omni_read_variable_string.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]
		self.lib.omni_read_variable_string.restype = None

		### WRITE

		self.lib.omni_write_variable_i8.argtypes = [ctypes.c_void_p, ctypes.c_int8]
		self.lib.omni_write_variable_i8.restype = None

		self.lib.omni_write_variable_i16.argtypes = [ctypes.c_void_p, ctypes.c_int16]
		self.lib.omni_write_variable_i16.restype = None

		self.lib.omni_write_variable_i32.argtypes = [ctypes.c_void_p, ctypes.c_int32]
		self.lib.omni_write_variable_i32.restype = None

		self.lib.omni_write_variable_i64.argtypes = [ctypes.c_void_p, ctypes.c_int64]
		self.lib.omni_write_variable_i64.restype = None

		self.lib.omni_write_variable_u8.argtypes = [ctypes.c_void_p, ctypes.c_uint8]
		self.lib.omni_write_variable_u8.restype = None

		self.lib.omni_write_variable_u16.argtypes = [ctypes.c_void_p, ctypes.c_uint16]
		self.lib.omni_write_variable_u16.restype = None

		self.lib.omni_write_variable_u32.argtypes = [ctypes.c_void_p, ctypes.c_uint32]
		self.lib.omni_write_variable_u32.restype = None

		self.lib.omni_write_variable_u64.argtypes = [ctypes.c_void_p, ctypes.c_uint64]
		self.lib.omni_write_variable_u64.restype = None

		self.lib.omni_write_variable_float.argtypes = [ctypes.c_void_p, ctypes.c_float]
		self.lib.omni_write_variable_float.restype = None

		self.lib.omni_write_variable_double.argtypes = [ctypes.c_void_p, ctypes.c_double]
		self.lib.omni_write_variable_double.restype = None

		self.lib.omni_write_variable_string.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
		self.lib.omni_write_variable_string.restype = None

		### MISC

		self.lib.omni_variable_has_changed.argtypes = [ctypes.c_void_p]
		self.lib.omni_variable_has_changed.restype = ctypes.c_bool

def _iface():
	global IFACE_INSTANCE
	if IFACE_INSTANCE == None:
		IFACE_INSTANCE = Iface()
	return IFACE_INSTANCE

def init(dll_file_path):
	global SHARED_LIBRARY_PATH
	SHARED_LIBRARY_PATH = dll_file_path

# ...
class Tree:
	def __init__(self, tree_id):
		self.cref = _iface().lib.omni_find_tree(tree_id)

# ...
class VariableBase:
	def __init__(self, tree, path):
		self.tree = tree
		self.path = path
		self.cref = None

	def has_changed(self):
		return _iface().lib.omni_variable_has_changed(self.cref)

# ...
class VariableI8(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_i8(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_i8(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_i8(self.cref, value)

# ...
class VariableI16(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_i16(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_i16(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_i16(self.cref, value)

# ...
class VariableI32(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_i32(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_i32(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_i32(self.cref, value)

# ...
class VariableI64(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_i64(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_i64(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_i64(self.cref, value)

# ...
class VariableU8(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_u8(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_u8(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_u8(self.cref, value)

# ...
class VariableU16(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_u16(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_u16(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_u16(self.cref, value)

# ...
class VariableU32(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_u32(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_u32(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_u32(self.cref, value)

# ...
class VariableU64(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_u64(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_u64(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_u64(self.cref, value)

# ...
class VariableFloat(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_float(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_float(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_float(self.cref, value)

# ...
class VariableDouble(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_double(tree.cref, path)

	def get(self):
		return _iface().lib.omni_read_variable_double(self.cref)

	def set(self, value):
		_iface().lib.omni_write_variable_double(self.cref, value)

# ...
class VariableString(VariableBase):
	def __init__(self, tree, path):
		VariableBase.__init__(self, tree, path)
		self.cref = _iface().lib.omni_find_variable_string(tree.cref, path)

	def get(self):
		buf = ctypes.create_string_buffer(256)
		_iface().lib.omni_read_variable_string(self.cref, buf, 256)
		return buf.value.decode("utf-8")

	def set(self, value):
		_iface().lib.omni_write_variable_string(self.cref, value)