local base={id=0,name="base"}
function base:new(i,name)
    local o ={}
    setmetatable(base,o)
    o.__index = self
    o.id = i or 0
    o.name = name or "base"
    return o
end

function base:show(o)
    local o = o or self
    for k,v in pairs(o)do
        -- if type(v) == "string" or "number" then
            print(k,v)
        -- end
    end
    print("--------------------------")
end
--*test
local human = base:new(1,"human")
--*test
function human:new(name,age)
    local o={}
    setmetatable(human,o)
    o.__index = human
    o.name = name or "human"
    o.age = age or 0
    o.id=2
    return o
end
local lixi = human:new("lixi",22)
local zhan = human:new("zhan",25)
base:show(human)
base:show(lixi)
base:show(zhan)
