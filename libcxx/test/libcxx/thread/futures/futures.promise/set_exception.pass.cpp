//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: libcpp-no-exceptions
// UNSUPPORTED: libcpp-has-no-threads
// UNSUPPORTED: c++98, c++03

// MODULES_DEFINES: _LIBCPP_DEBUG_USE_EXCEPTIONS
// MODULES_DEFINES: _LIBCPP_DEBUG=0

// Can't test the system lib because this test enables debug mode
// UNSUPPORTED: with_system_cxx_lib

// <future>

// class promise<R>

// void set_exception(exception_ptr p);
// Test that a null exception_ptr is diagnosed.

#define _LIBCPP_DEBUG 0
#define _LIBCPP_DEBUG_USE_EXCEPTIONS
#include <future>
#include <exception>
#include <cstdlib>
#include <cassert>


int main()
{
    typedef std::__libcpp_debug_exception ExType;
    {
        typedef int T;
        std::promise<T> p;
        try {
            p.set_exception(std::exception_ptr());
            assert(false);
        } catch (ExType const&) {
        }
    }
    {
        typedef int& T;
        std::promise<T> p;
        try {
            p.set_exception(std::exception_ptr());
            assert(false);
        } catch (ExType const&) {
        }
    }
}
