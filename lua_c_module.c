#include <stdio.h>
#include <string.h>

#include "lua.h"
#include "lauxlib.h"

static int _internal_get_random_number(void)
{
    return 4; // chosen by fair dice roll.
              // guaranteed to be random.
}

int get_random_number(lua_State *L)
{
    int r = _internal_get_random_number();
    lua_pushnumber(L, r);

    return 1;
}

int add_four(lua_State *L)
{
    lua_Number n = luaL_checknumber(L, -1);
    int r = 4 + n;
    lua_pushnumber(L, r);

    return 1;
}

int luaopen_lua_c_module(lua_State *L)
{
    const char *msg = "hello world";

    luaL_Reg fs[] = {
        { "get_random_number", get_random_number },
        { "add_four", add_four },
        { NULL, NULL },
    };

    lua_newtable(L);
    lua_pushlstring(L, msg, strlen(msg));
    lua_setfield(L, 2, "hello");

    luaL_Reg *reg = fs;
    for (; reg->name != NULL; reg++)
    {
        lua_pushcfunction(L, reg->func);
        lua_setfield(L, 2, reg->name);
    }

    return 1;
}
