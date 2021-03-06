-- local human = {name = "human",age = 0}
-- function human:new(o)
--     local o = o or {__index=human}
--     setmetatable(o,self)
--     return self
-- end;;;;;
-- Meta class
Shape = {area = 0}
-- 基础类方法 new
function Shape:new (o,side)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  side = side or 0
  self.area = side*side;
  return o
end
-- 基础类方法 printArea
function Shape:printArea (o)--!模拟多态  父类方法调用子类属性或者方法
    local o = o or self
  print("面积为 ",o.area)
end

-- 创建对象
local myshape = Shape:new(nil,10)
myshape:printArea()
local Square = Shape:new()--!这是继承的关键





-- 派生类方法 new
function Square:new (o,side)
  o = o or Shape:new(o,side)--!这是继承的关键
  setmetatable(o, self)
  self.__index = self
  return o
end

-- 派生类方法 printArea
function Square:printArea ()
  print("正方形面积为 ",self.area)
end


-- 创建对象
mysquare = Square:new(nil,10)
mysquare:printArea()

Rectangle = Shape:new()


Rectangle = Shape:new()
-- 派生类方法 new
function Rectangle:new (o,length,breadth)
  o = o or Shape:new(o)
  setmetatable(o, self)
  self.__index = self
  self.area = length * breadth
  return o
end

-- 派生类方法 printArea
function Rectangle:printArea ()
  print("矩形面积为 ",self.area)
end



-- 创建对象
myrectangle = Rectangle:new(nil,10,20)
myrectangle:printArea()


local test=Rectangle:new(nil,9,30)

-- shape:printArea(test)
myshape:printArea(test)
myshape:printArea()