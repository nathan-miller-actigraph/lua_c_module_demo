cmake_minimum_required(VERSION 2.6)
project(lua_c_module)

find_package(Lua51 REQUIRED)

include_directories(${LUA_INCLUDE_DIR})

if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wno-long-long")
endif()

add_library(lua_c_module SHARED lua_c_module.c)
target_link_libraries(lua_c_module ${LUA_LIBRARIES} usb-1.0)
set_target_properties(lua_c_module PROPERTIES PREFIX "")

install(TARGETS lua_c_module DESTINATION lib/lua/5.1)
