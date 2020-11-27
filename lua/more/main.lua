local human = {name = "human",age = 0}
function human:new(o)
    local o = o or {__index=human}
    setmetatable(o,self)
    return self
end;;;;;
