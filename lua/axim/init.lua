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



_G.vec2f = require("axim.vect2f")

require("axim.mobjects.mobject")
_G.Rect = require("axim.mobjects.rect")


local ffi = require("ffi")
ffi.cdef [[
  void axm_scene_add(Mobject* mobject);
]]

_G.add = ffi.C.axm_scene_add