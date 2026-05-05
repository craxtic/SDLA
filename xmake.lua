add_rules("mode.debug", "mode.release")
set_languages("c++23")

--- for development
add_includedirs("include") ---
set_warnings("allextra")
set_policy("build.warning", true)


--- @axim-engine
--- the rendering engine
target("axim-engine") do
  set_kind("shared")
  add_cxflags("-fvisibility=hidden")
  add_defines("AXIM_API_EXPORTS")
  add_files("src/animations/**.cpp")
  add_files("src/mobjects/**.cpp")
  add_files("src/scene/**.cpp")
  
  add_links("skia")
end



--- @axim-presenter
--- provide presenter to output frames rendered by the engine 
--- either preview, export, or integrate into an external enviroment
target("axim-presenters") do
  set_kind("shared")
  add_cxflags("-fvisibility=hidden")
  add_defines("AXIM_API_EXPORTS")
  add_files("src/presenters/**.cpp")
  
  add_links("SDL3")
end



--- @axim-lua
--- axim bindings to lua script 
target("axim-lua") do
  set_kind("shared")
  add_cxflags("-fvisibility=hidden")
  add_defines("AXIM_API_EXPORTS")
  add_files("src/bindings/**.cpp")

  add_links("lua5.4")
  add_includedirs("/usr/include/lua5.4")
end



--- @header-files
--- for installation
target("axim-headers") do 
  set_kind("headeronly")
  add_headerfiles("include/(**.h)") 
end


--- @axim-app
--- the application command-line interface
target("axim") do 
  set_kind("binary")
  add_files("app/**.cpp")
  add_deps("axim-engine")
  add_deps("axim-presenters")
  add_deps("axim-lua")
  set_targetdir("$(projectdir)/app")
  
  add_links("lua5.4")
  add_includedirs("/usr/include/lua5.4")
end


