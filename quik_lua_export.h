#ifndef QUIK_LUA_EXPORT_H
#define QUIK_LUA_EXPORT_H

extern "C" {
#define LUA_LIB
#define LUA_BUILD_AS_DLL

#include <lauxlib.h>
#include <lua.h>
#include <luaconf.h>

LUALIB_API int luaopen_quik_lua_export(lua_State *L);
}

#endif // quik_lua_export_H
