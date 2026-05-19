--     _          _
--    / \   __  _(_)_ __ ___
--   / _ \  \ \/ / | '_ ` _ \
--  / ___ \  >  <| | | | | | |
-- /_/   \_\/_/\_\_|_| |_| |_|
--
-- Copyright (c) 2026 The Axim Team
--
-- This Source Code Form is subject to the terms of the Mozilla Public
-- License, v. 2.0. If a copy of the MPL was not distributed with this
-- file, You can obtain one at https://mozilla.org.


local ffi = require("ffi")

ffi.cdef [[
  
  typedef struct {
    void *vptr;
    float z_index;
  } Mobject;

  Mobject* axm_Rect(vec2f a, vec2f b);


]]

_G.Rect = ffi.C.axm_Rect