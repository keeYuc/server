local o ={id=1}
local o1={}
setmetatable(o,o1)
function show(o)
    for k,v in pairs(o)do
        print(k,v)
    end
end
o1.id=20
show(o)
show(o1)
o.id=100
show(o)
show(o1)







