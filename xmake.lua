add_rules("mode.debug")

set_languages("c++23")
add_includedirs("include") -------

target("axim")
  set_kind("shared")
  add_files("src/**.cpp")
  add_cxflags("-fvisibility=hidden")
  add_defines("AXIM_API_EXPORTS")
  add_links("SDL3")
  add_links("skia")

target("example")
  set_kind("binary")
  add_files("example.cpp")
  add_deps("axim")


