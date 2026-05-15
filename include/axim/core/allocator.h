/*     _          _
 *    / \   __  _(_)_ __ ___
 *   / _ \  \ \/ / | '_ ` _ \
 *  / ___ \  >  <| | | | | | |
 * /_/   \_\/_/\_\_|_| |_| |_|
 *
 * Copyright (c) 2026 The Axim Team
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org.
 */

#pragma once

#include <axim/config.h>
#include <cstddef>
#include <cstring>

namespace axm {

using byte = unsigned char;

class AXIM_CORE_API Allocator {
  byte *begin;
  byte *current;
  byte *end;

public:

  Allocator() = default;

  explicit Allocator(size_t capacity);

  ~Allocator();

  [[nodiscard]] void *allocate(size_t n, size_t alignment = alignof(max_align_t));


  template<typename T>
  inline T *allocate(size_t count){
    return reinterpret_cast<T*>(allocate(sizeof(T) * count, alignof(T)));
  }

  inline void reset(){
    current = begin;
  };

  inline void clean(){
    std::memset(begin, 0, capacity());
  };

  [[nodiscard]] inline size_t capacity(){
    return (end - begin);
  }

};



}
