add_rules("mode.debug")

set_languages("c++23")
add_includedirs("include") -------

target("sdla")
  set_kind("shared")
  add_files("src/**.cpp")
  add_cxflags("-fvisibility=hidden")
  add_defines("SDLA_API_EXPORTS")
  add_links("SDL3")
  add_links("skia")

target("main")
  set_kind("binary")
  add_files("main-test.cpp")
  add_deps("sdla")
