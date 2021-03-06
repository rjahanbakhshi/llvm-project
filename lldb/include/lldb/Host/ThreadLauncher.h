//===-- ThreadLauncher.h -----------------------------------------*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef lldb_Host_ThreadLauncher_h_
#define lldb_Host_ThreadLauncher_h_

#include "lldb/Host/HostThread.h"
#include "lldb/Utility/Status.h"
#include "lldb/lldb-types.h"

#include "llvm/ADT/StringRef.h"

namespace lldb_private {

class ThreadLauncher {
public:
  static HostThread
  LaunchThread(llvm::StringRef name, lldb::thread_func_t thread_function,
               lldb::thread_arg_t thread_arg, Status *error_ptr,
               size_t min_stack_byte_size = 0); // Minimum stack size in bytes,
                                                // set stack size to zero for
                                                // default platform thread stack
                                                // size

  struct HostThreadCreateInfo {
    std::string thread_name;
    lldb::thread_func_t thread_fptr;
    lldb::thread_arg_t thread_arg;

    HostThreadCreateInfo(const char *name, lldb::thread_func_t fptr,
                         lldb::thread_arg_t arg)
        : thread_name(name ? name : ""), thread_fptr(fptr), thread_arg(arg) {}
  };
};
}

#endif
