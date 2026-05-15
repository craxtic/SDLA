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

#include "axim/config.h"
#include <axim/core/allocator.h>

namespace axm {


class AXIM_CORE_API Cloud {

public:
  Allocator allocator;
  Cloud *next = nullptr;

  Cloud(size_t capacity): allocator(Allocator(capacity)){}
  
  ~Cloud();

  void* allocate(size_t n, size_t alignment = alignof(max_align_t));

  template<typename T>
  inline T* allocate(size_t count){
    return reinterpret_cast<T*>(allocate(sizeof(T) * count, alignof(T)));
  }
  
};



}