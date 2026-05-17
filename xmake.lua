add_rules("mode.debug", "mode.release")
set_languages("c++23")

add_requires("skia", {system = true}) -- require to manually install
add_requires("libsdl3")
add_requires("luajit")
add_requires("catch2") 


--- for development
add_includedirs("$(projectdir)/include") ---
add_includedirs("$(projectdir)/app/include")
set_warnings("allextra")
set_policy("build.warning", true)

local function get_lua_ffi_dir() 
  local lua_path = path.join(os.projectdir(), "lua")
  if is_host("windows") then
    return lua_path:gsub("\\", "\\\\")
  end
end


--- @axim-core
--- 
target("axim-core") do 
  set_kind("shared")
  set_symbols("hidden")
  add_defines("AXIM_CORE_EXPORTS")
  add_files("src/core/**.cpp")
end

--- @axim-engine
--- the rendering engine
target("axim-engine") do
  set_kind("shared")
  set_symbols("hidden")
  add_defines("AXIM_ENGINE_EXPORTS")
  add_files("src/animations/**.cpp")
  add_files("src/mobjects/**.cpp")
  add_files("src/scene/**.cpp")
  
  add_packages("skia")
end



--- @axim-presenter
--- provide presenter to output frames rendered by the engine 
--- either preview, export, or integrate into an external enviroment
target("axim-presenters") do
  set_kind("shared")
  set_symbols("hidden")
  add_defines("AXIM_PRESENTER_EXPORTS")
  add_files("src/presenters/**.cpp")
  
  add_packages("libsdl3", "skia")
end


--- @axim-app
--- the application command-line interface
target("axim") do 
  set_kind("binary")
  add_files("app/src/**.cc")
  add_deps("axim-core", "axim-engine", "axim-presenters")

  if is_plat("linux", "bsd") then
    add_ldflags("-rdynamic", {force = true})
  end

  add_packages("skia", "libsdl3", "luajit")

  add_defines("AXIM_LUA_DIR=" ..'"'.. get_lua_ffi_dir() .. '"')
end




--- @axim-test
--- compile every test files, run and write to test/reports/name.xml
for _, file in ipairs(os.files("test/src/**.cxx")) do
  local name = path.basename(file)

  target(name) do
    set_kind("binary")
    set_default(false)
    add_files(file)
    add_packages("catch2")
    
    before_test(function () 
      os.mkdir("test/reports")
    end)

    add_tests("test", {
      runargs = {
        "-r", "xml", 
        "-o", path.join(os.projectdir(), "test", "reports", name .. ".xml")
      }
    })
    
  end
end



--- @axim-report
--- parse the test/reports/*.xml and report test results
task("report") do
  on_run(function ()
    local paths = path.join(os.projectdir(), "test", "reports", "*.xml")
    for _, file in ipairs(os.files(paths)) do
      -- print("FILE: " .. file)
      os.execv("lua", {"test/output-reports.lua", file})
      
    end
  end)

  set_menu {
    usage = "xmake report [options]",
    description = "View full test results.",
    options = {
      "-c", 
    }
  }
end


