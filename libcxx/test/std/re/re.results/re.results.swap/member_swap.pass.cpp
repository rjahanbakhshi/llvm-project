//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <regex>

// class match_results<BidirectionalIterator, Allocator>

// void swap(match_results& that);

#include <regex>
#include <cassert>
#include "test_macros.h"

void
test()
{
    std::match_results<const char*> m1;
    const char s[] = "abcdefghijk";
    assert(std::regex_search(s, m1, std::regex("cd((e)fg)hi")));
    std::match_results<const char*> m2;

    std::match_results<const char*> m1_save = m1;
    std::match_results<const char*> m2_save = m2;

    m1.swap(m2);

    assert(m1 == m2_save);
    assert(m2 == m1_save);
}

int main()
{
    test();
}
