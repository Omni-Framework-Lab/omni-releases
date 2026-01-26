#pragma once
#include "omni_iface_c.h"
#include <iostream>
#include <type_traits>

namespace omni
{
	class Tree
	{
	public:
		std::string _id;
		Omni_Tree* _ctree = nullptr;

		Tree(std::string id)
			: _id(id)
		{
			_ctree = omni_find_tree(id.c_str());
		}

		Tree(const Tree& other)
			: Tree(other._id.c_str())
		{}

		Tree& operator=(const Tree& other)
		{
			if (this != &other)
			{
				_id = other._id;
				_ctree = omni_find_tree(_id.c_str());
			}
			return *this;
		}

		~Tree()
		{
			if (_ctree)
				omni_tree_free(_ctree);
		}

		bool is_valid() const
		{
			return _ctree;
		}
	};

	template<typename T>
	class VariableT
	{
		const Tree _tree;
		const std::string _path;
		Omni_Variable* _cvar = nullptr;

	public:
		VariableT(const Tree& tree, const std::string& path)
			: _tree(tree)
			, _path(path)
		{
			if constexpr (std::is_same<T, int8_t>())
			{
				_cvar = omni_find_variable_i8(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, int16_t>())
			{
				_cvar = omni_find_variable_i16(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, int32_t>())
			{
				_cvar = omni_find_variable_i32(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, int64_t>())
			{
				_cvar = omni_find_variable_i64(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, uint8_t>())
			{
				_cvar = omni_find_variable_u8(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, uint16_t>())
			{
				_cvar = omni_find_variable_u16(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, uint32_t>())
			{
				_cvar = omni_find_variable_u32(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, uint64_t>())
			{
				_cvar = omni_find_variable_u64(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, float>())
			{
				_cvar = omni_find_variable_float(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, double>())
			{
				_cvar = omni_find_variable_double(tree._ctree, path.c_str());
			}
			else if constexpr (std::is_same<T, std::string>())
			{
				_cvar = omni_find_variable_string(tree._ctree, path.c_str());
			}
			else
			{
				exit(111);
			}
		}

		VariableT(VariableT&& other) = delete;

		VariableT(const VariableT& other)
			: VariableT(other._tree, other._path)
		{}

		VariableT& operator=(const VariableT& other)
		{
			if (this != &other)
			{
				_tree = other._tree;
				_path = other._path;
				_cvar = omni_variable_clone(other._cvar);
			}
			return *this;
		}

		~VariableT()
		{
			if (_cvar)
				omni_variable_free(_cvar);
		}

		T get() const
		{
			if constexpr (std::is_same<T, int8_t>())
			{
				return omni_read_variable_i8(_cvar);
			}
			else if constexpr (std::is_same<T, int16_t>())
			{
				return omni_read_variable_i16(_cvar);
			}
			else if constexpr (std::is_same<T, int32_t>())
			{
				return omni_read_variable_i32(_cvar);
			}
			else if constexpr (std::is_same<T, int64_t>())
			{
				return omni_read_variable_i64(_cvar);
			}
			else if constexpr (std::is_same<T, uint8_t>())
			{
				return omni_read_variable_u8(_cvar);
			}
			else if constexpr (std::is_same<T, uint16_t>())
			{
				return omni_read_variable_u16(_cvar);
			}
			else if constexpr (std::is_same<T, uint32_t>())
			{
				return omni_read_variable_u32(_cvar);
			}
			else if constexpr (std::is_same<T, uint64_t>())
			{
				return omni_read_variable_u64(_cvar);
			}
			else if constexpr (std::is_same<T, float>())
			{
				return omni_read_variable_float(_cvar);
			}
			else if constexpr (std::is_same<T, double>())
			{
				return omni_read_variable_double(_cvar);
			}
			else if constexpr (std::is_same<T, std::string>())
			{
				char buf[DTREE_VARIABLE_MAX_SIZE];
				omni_read_variable_string(_cvar, buf, DTREE_VARIABLE_MAX_SIZE);
				return std::string(buf);
			}
			else
			{
				exit(2134);
			}
		}

		void set(T value)
		{
			if constexpr (std::is_same<T, int8_t>())
			{
				omni_write_variable_i8(_cvar, value);
			}
			else if constexpr (std::is_same<T, int16_t>())
			{
				omni_write_variable_i16(_cvar, value);
			}
			else if constexpr (std::is_same<T, int32_t>())
			{
				omni_write_variable_i32(_cvar, value);
			}
			else if constexpr (std::is_same<T, int64_t>())
			{
				omni_write_variable_i64(_cvar, value);
			}
			else if constexpr (std::is_same<T, uint8_t>())
			{
				omni_write_variable_u8(_cvar, value);
			}
			else if constexpr (std::is_same<T, uint16_t>())
			{
				omni_write_variable_u16(_cvar, value);
			}
			else if constexpr (std::is_same<T, uint32_t>())
			{
				omni_write_variable_u32(_cvar, value);
			}
			else if constexpr (std::is_same<T, uint64_t>())
			{
				omni_write_variable_u64(_cvar, value);
			}
			else if constexpr (std::is_same<T, float>())
			{
				omni_write_variable_float(_cvar, value);
			}
			else if constexpr (std::is_same<T, double>())
			{
				omni_write_variable_double(_cvar, value);
			}
			else if constexpr (std::is_same<T, std::string>())
			{
				omni_write_variable_string(_cvar, value.c_str(), value.size());
			}
			else
			{
				exit(2134);
			}
		}

		bool has_changed() const
		{
			return omni_variable_has_changed(_cvar) != 0;
		}
	};
}