local xml2lua = require("external.xml2lua.xml2lua")
local handler = require("external.xml2lua.xmlhandler.tree")

if #arg ~= 1 then
  print("missing xml file")
  return
end

local parser = xml2lua.parser(handler)
local content = xml2lua.loadFile(arg[1])
parser:parse(content)

local tree = handler.root.Catch2TestRun



local colors = {
  reset = "\27[0m",
  red   = "\27[31m",
  green = "\27[32m",
  -- brgreen = "\27[92m",
  blue  = "\27[34m",
  grey = "\27[90m"
}

local function fmtc(color, str)
  return color .. str ..colors.reset
end


local test_cases = tree.TestCase
print(fmtc(colors.blue, "-> ".. tree._attr["name"]))
for i, test_case in ipairs(test_cases) do
  
  local overall_result = test_case.OverallResult._attr
  

  local hl = ""
  if overall_result["success"] == "true" then
    hl = colors.green
  else    
    hl = colors.red
  end

  --- test[1](test/src/vector.cxx::23) 

  local info = test_case._attr
  local info = string.format("(%s,%s::%s) ", info["name"], info["filename"], info["line"])
  info = fmtc(colors.grey, info)
  

  local header = fmtc(hl, " + test["..i.."] - ") .. info
  
  local bm_result = test_case.BenchmarkResults
  if bm_result then
    local name =  bm_result._attr["name"] 
    local txt =  fmtc(hl, string.format("- benchmark(%s)", name)) 
    print(header .. txt)

    local mean = bm_result.mean._attr
    local stdiv = bm_result.standardDeviation._attr
    local bm = bm_result._attr

    local result = string.format(
[[
    runs[%s * %s], speed[%s, %s], stdiv[%s] ]],
    bm["samples"], bm["iterations"], mean["lowerBound"], mean["upperBound"], stdiv["value"])
    print(result)
  else
    local txt = string.format("")
    txt = fmtc(hl, txt)
    print(header .. txt)
  end
  
end

local summary = colors.green .. "successes: ".. tree.OverallResultsCases._attr["successes"]
summary = summary .. colors.reset .. " - "
summary = summary..colors.red.."failures: "..tree.OverallResultsCases._attr["failures"]
print("   "..summary)
