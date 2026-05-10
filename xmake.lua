add_rules("mode.debug", "mode.release")
set_languages("c++23")

add_requires("skia", {system = true}) -- require to manually install
add_requires("libsdl3")
add_requires("luajit")
add_requires("sol2")
add_requires("ffmpeg", {configs = {binaryonly = true}})
add_requires("catch2") 



--- for development
add_includedirs("$(projectdir)/include") ---
set_warnings("allextra")
set_policy("build.warning", true)


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



--- @axim-lua
--- axim bindings to lua script 
target("axim-lua") do
  set_kind("shared")
  set_symbols("hidden")
  add_defines("AXIM_LUA_EXPORTS")
  add_files("src/bindings/**.cpp")

  add_deps("axim-engine", "axim-presenters")
  add_packages("skia", "sol2", "luajit")
end



--- @header-files
--- for installation
-- target("axim-headers") do 
--   set_kind("headeronly")
--   add_headerfiles("include/(**.h)") 
-- end


--- @axim-app
--- the application command-line interface
target("axim") do 
  set_kind("binary")
  add_files("app/**.cpp")
  add_deps("axim-engine")
  add_deps("axim-presenters")
  add_deps("axim-lua")
  -- set_targetdir("$(projectdir)/app")
  
  add_packages("skia", "libsdl3", "sol2", "luajit")
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

    }
  }
end


