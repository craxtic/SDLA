
_G.vec2f = require("axim.vect2f")

require("axim.mobjects.mobject")
_G.Rect = require("axim.mobjects.rect")


local ffi = require("ffi")
ffi.cdef [[
  void axm_scene_add(Mobject* mobject);
]]

_G.add = ffi.C.axm_scene_add