
-- local function test()
--     print("i'm test")
-- end

-- local function hook()
--     print("i'm hook")
-- end
-- local message;
-- print(debug.traceback(test))
local mytable={}
mytable.a=1
mytable.b=222

for k,v in pairs(mytable)do
    print(k,v)
end
