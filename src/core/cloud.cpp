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

#include <axim/core/cloud.h>
#include <iostream>

namespace axm {

void *Cloud::allocate(size_t n, size_t alignment) {

  Cloud *cloud;

  for (cloud = this; cloud != nullptr; cloud = cloud->next) {
    void *array = cloud->allocator.allocate(n, alignment);
    if (array)
      return array;

    if (cloud->next == nullptr) {
      std::cout << "new Cloud()\n";
      cloud->next = new Cloud(n + this->allocator.capacity());
    }
  }

  std::cerr << "failed to allocate new Cloud()\n";
  return nullptr;
}

Cloud::~Cloud() {
  if (this->next)
    delete this->next;
}

} // namespace axm