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

ffi.cdef([[
  typedef struct {
    float x, y;
  } vec2f;
]])

---@class vec2f
---@field x number
---@field y number
local metatable = {
  __call = function (_, x, y)
    return ffi.new("vec2f", x or 0, y or 0)
  end,
  __tostring = function (self)
    return string.format("(%.2f,%.2f)", self.x, self.y)
  end
}

return ffi.metatype("vec2f", metatable)

