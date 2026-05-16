local ffi = require("ffi")

ffi.cdef [[
  
  typedef struct {
    void *vptr;
    float z_index;
  } Mobject;

]]

local metatable = {
  
}

-- ffi.metatype("Mobject", metatable)