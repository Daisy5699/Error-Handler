#pragma once

#ifndef error_hxx
#define error_hxx

namespace utility
{
	template<typename t>
	class c_error
	{
	private:
		bool m_success;
		t m_value;
		std::string m_msg;
		const char* m_file_name;
		int m_line;
	public:
		c_error(t value) { this->m_success = true; this->m_value = value; }
		c_error(const std::string& msg, const
			char* file_name, int line) {this->m_success = false; this->m_msg = msg; this->m_file_name = file_name;
			this->m_line = line; }

		auto is_error() -> bool
		{
			return !this->m_success;
		}

		auto get() -> t
		{
			if (!this->m_success) throw std::runtime_error("cannot get, due to error result");
			return this->m_value;
		}

		auto has_msg() -> std::string
		{
			return this->m_msg;
		}

		auto file_name() -> const char*
		{
			return this->m_file_name;
		}

		auto line() -> int
		{
			return this->m_line;
		}
	};
}

#endif // error_hxx
