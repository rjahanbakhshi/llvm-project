//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class _IntType = int>
// class uniform_int_distribution
// {
//     class param_type;

#include <random>
#include <limits>
#include <cassert>

int main()
{
    {
        typedef std::uniform_int_distribution<long> D;
        typedef D::param_type param_type;
        param_type p;
        assert(p.a() == 0);
        assert(p.b() == std::numeric_limits<long>::max());
    }
    {
        typedef std::uniform_int_distribution<long> D;
        typedef D::param_type param_type;
        param_type p(5);
        assert(p.a() == 5);
        assert(p.b() == std::numeric_limits<long>::max());
    }
    {
        typedef std::uniform_int_distribution<long> D;
        typedef D::param_type param_type;
        param_type p(5, 10);
        assert(p.a() == 5);
        assert(p.b() == 10);
    }
}
