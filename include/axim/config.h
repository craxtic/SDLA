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


#define AXIM_VERSION_MAJOR 0
#define AXIM_VERSION_MINOR 0
#define AXIM_VERSION_PATCH 0



#define AXIM_API_EXPORT __attribute__((__visibility__("default")))
#define AXIM_API_IMPORT __attribute__((__visibility__("default")))


#if defined (AXIM_API_EXPORTS)

#define AXIM_API AXIM_API_EXPORT

#else

#define AXIM_API AXIM_API_IMPORT

#endif


#define MOBJECT_COUNT_PER_SCENE_PROBABLY 100
