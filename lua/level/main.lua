-- os.execute("pwd")
-- local str=io.popen("pwd")
-- str=str:read("a")
-- package.path=package.path..";"..str..";"
-- local tool =require"tool"

local test={name="abc"}
function test:test(test,str)
    if not str then
        str=self.name
    end
    print(str)
end
function aaaa()
    print("aaaa")
end


pcall(aaaa)
pcall(test.test,test)


