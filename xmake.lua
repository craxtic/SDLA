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
  add_includedirs("/usr/include/lua5.4")
  add_links("lua5.4")

target("example")
  set_kind("binary")
  add_files("example/example.cpp")
  add_deps("axim")
  set_targetdir("$(projectdir)/example")
  add_includedirs("/usr/include/lua5.4")
  add_links("lua5.4")

