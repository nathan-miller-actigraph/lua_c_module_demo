local m = require 'lua_c_module'

print("m", m)
print("hello", m.hello)
print("random", m.get_random_number())
print("5 + 4 =", m.add(5, 4))
print("9 + 7 =", m.add(9, 7))

print(pcall(function()
    m.add("", 1)
end))

print(pcall(function()
    m.add(1, "")
end))
