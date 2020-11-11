#include "math.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int solve(lua_State *l)
{
	double a = luaL_checknumber(l, 1);
	double b = luaL_checknumber(l, 2);
	double c = luaL_checknumber(l, 3);
	
	double koeff = b * b - 4 * a * c;
	
	if(koeff < 0)
	{
		lua_pushnil(l);
		lua_pushnil(l);
	}
	else if(koeff > 0)
	{
		double res_1 = (-b - sqrtf(koeff)) / (2 * a);
		double res_2 = (-b + sqrtf(koeff)) / (2 * a);
		lua_pushnumber(l, res_1);
		lua_pushnumber(l, res_2);
	}
	else
	{
		lua_pushnil(l);
		lua_pushnumber(l, -b / (2 * a));
	}

	return 2;
}

int main()
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);	
	
	luaL_loadfile(l, "Lab_11.lua");	
	lua_pcall(l, 0, 0, 0);

	lua_pushcfunction(l, solve);
	lua_setglobal(l, "quart");

	lua_getglobal(l, "run_Math");
	lua_pcall(l, 0, 0, 0);
	lua_close(l);
	return 0;
}


