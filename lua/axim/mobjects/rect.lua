local ffi = require("ffi")

ffi.cdef[[
  Mobject* axm_Rect(vec2f a, vec2f b);
]]

return function (a, b)
  return ffi.C.axm_Rect(a, b)
end