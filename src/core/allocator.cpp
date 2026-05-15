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

#include <axim/core/allocator.h>
#include <cassert>
#include <cstdint>
#include <cstdlib>

namespace axm {

Allocator::Allocator(size_t capacity) {
  begin = reinterpret_cast<byte *>(malloc(capacity));
  assert(begin);
  current = begin;
  end = begin + capacity;
}

Allocator::~Allocator() {
  if (begin)
    free(begin);
}

void *Allocator::allocate(size_t n, size_t alignment) {

  assert(n > 0);

  uintptr_t current_addr = reinterpret_cast<uintptr_t>(current);
  uintptr_t aligned_addr = (current_addr + alignment - 1) & ~(alignment - 1);

  current = reinterpret_cast<byte *>(aligned_addr);

  // assert(n > static_cast<size_t>(end - current));
  if (n > static_cast<size_t>(end - current)) {
    return nullptr;
  }

  byte *ptr = current;
  current += n;
  return ptr;
}

} // namespace axm