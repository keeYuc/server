-- #!/bin/lua
local a={};
coroutine.wrap()=function ()
    print("i'm coroutine");
end

coroutine.resume();