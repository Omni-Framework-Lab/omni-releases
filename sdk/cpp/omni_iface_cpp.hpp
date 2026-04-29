#pragma once
#include "omni_iface_c.h"
#include <iostream>
#include <type_traits>
#include <vector>
#include <memory>

namespace omni
{
	/*! ... */
	class Variable
	{
	protected:
		Variable() = default;

	public:
		virtual ~Variable()
		{
			if (_cvar)
				omni_variable_free(_cvar);
		}

		const char* path() const
		{
			return omni_variable_path(_cvar);
		}

		uint8_t type() const
		{
			return omni_variable_type(_cvar);
		}

		uint16_t size() const
		{
			return omni_variable_size(_cvar);
		}

		bool is_alias() const
		{
			return omni_variable_is_alias(_cvar) != 0;
		}

	protected:
		Omni_Variable* _cvar = nullptr;
	};


	/*! ... */
	class Tree
	{
	public:
		std::string _id;
		Omni_Tree* _ctree = nullptr;

		Tree()
		{}

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
			if (this == &other)
				return *this;

			if (_ctree)
				omni_tree_free(_ctree);

			_id = other._id;
			_ctree = omni_find_tree(_id.c_str());
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

		std::vector<std::shared_ptr<Variable>> list_variables() const;
	};


	/*! ... */
	template<typename T>
	class VariableT : public Variable
	{
		Tree _tree;
		std::string _path;

	public:
		VariableT()
		{}

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
				if (_cvar)
				{
					omni_variable_free(_cvar);
				}
				_tree = other._tree;
				_path = other._path;
				_cvar = omni_variable_clone(other._cvar);
			}
			return *this;
		}

		~VariableT() override
		{}

		bool is_valid() const
		{
			return _cvar != nullptr;
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
				char buf[OMNI_VARIABLE_MAX_SIZE];
				omni_read_variable_string(_cvar, buf, OMNI_VARIABLE_MAX_SIZE);
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

	///////////////////////////////////////////////////////////////////
	// Tree definition
	///////////////////////////////////////////////////////////////////

	inline std::vector<std::shared_ptr<Variable>> Tree::list_variables() const
	{
		int len = 0;
		Omni_Variable** vars = omni_list_variables(_ctree, &len);

		std::vector<std::shared_ptr<Variable>> variables;
		variables.reserve(len);

		for (int i = 0; i < len; ++i)
		{
			Omni_Variable* var = vars[i];
			const char* path = omni_variable_path(var);
			const auto type = omni_variable_type(var);

			switch (type)
			{
				case OMNI_INT8:
					variables.push_back(std::make_shared<VariableT<int8_t>>(*this, path));
					break;
				case OMNI_INT16:
					variables.push_back(std::make_shared<VariableT<int16_t>>(*this, path));
					break;
				case OMNI_INT32:
					variables.push_back(std::make_shared<VariableT<int32_t>>(*this, path));
					break;
				case OMNI_INT64:
					variables.push_back(std::make_shared<VariableT<int64_t>>(*this, path));
					break;
				case OMNI_UINT8:
					variables.push_back(std::make_shared<VariableT<uint8_t>>(*this, path));
					break;
				case OMNI_UINT16:
					variables.push_back(std::make_shared<VariableT<uint16_t>>(*this, path));
					break;
				case OMNI_UINT32:
					variables.push_back(std::make_shared<VariableT<uint32_t>>(*this, path));
					break;
				case OMNI_UINT64:
					variables.push_back(std::make_shared<VariableT<uint64_t>>(*this, path));
					break;
				case OMNI_FLOAT:
					variables.push_back(std::make_shared<VariableT<float>>(*this, path));
					break;
				case OMNI_DOUBLE:
					variables.push_back(std::make_shared<VariableT<double>>(*this, path));
					break;
				case OMNI_STRING:
					variables.push_back(std::make_shared<VariableT<std::string>>(*this, path));
					break;
				default:
					std::cerr << "Unknown variable type: " << static_cast<int>(type) << " for variable with path: " << path << std::endl;
					exit(1);
					break;
			}
		}
		omni_free_variables(vars);
		return variables;
	}

}
