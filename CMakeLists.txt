cmake_minimum_required(VERSION 2.6)
project(lua_c_module)

include_directories("/usr/include/lua5.1/")

if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wno-long-long")
endif()

add_library(lua_c_module SHARED lua_c_module.c)
set_target_properties(lua_c_module PROPERTIES PREFIX "")

install(TARGETS lua_c_module DESTINATION lib/lua/5.1)
