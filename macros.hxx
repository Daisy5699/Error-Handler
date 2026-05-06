#pragma once
#include "error.hxx"

#ifndef macros_hxx
#define macros_hxx

#define err(msg) utility::c_error(msg, __FILE__, __LINE__)

#endif // macros_hxx
