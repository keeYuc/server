-- local path=io.popen("ls")
-- path=path:read("a")

local a={}
for i = 1, 8,2 do
    table.insert(a,tostring(i))
end
for k,v in pairs(a) do
    print(k,v)
end
