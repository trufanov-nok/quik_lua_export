#include "quik_lua_export.h"
#include <iostream>
#include <cstdio>

const int dat_time_buf = 23;
struct TradeData
{
    const char* code;
    char* contract;
    double price;
    unsigned long amount;
    char dat_time[dat_time_buf];
    unsigned long trade_id;
    bool Nosystem;
};

double getNumberField(lua_State *L, const char* field)
{
    lua_getfield(L, -1, field);
    if (!lua_isnumber(L, -1))
        luaL_error(L, "invalid %s", field);

    const lua_Number result = lua_tonumber(L, -1);
    lua_pop(L, 1);
    return (double) result;
}

const char* getStringField(lua_State *L, const char* field)
{
    lua_getfield(L, -1, field);
    if (!lua_isstring(L, -1))
        luaL_error(L, "invalid %s", field);

    const char* result = lua_tostring(L, -1);
    lua_pop(L, 1);
    return result;
}

int forOnAllTrade(lua_State *L)
{
    if (!lua_istable(L, -1))
        luaL_error(L, "OnAllTrade argument is not a table");

    TradeData data;

    data.code = getStringField(L, "sec_code");
    data.price = getNumberField(L, "price");
    data.amount = getNumberField(L, "qty");
    data.trade_id = getNumberField(L, "trade_num");

    lua_getfield(L, -1, "datetime");
    if (!lua_istable(L, -1))
    {
        luaL_error(L, "datatime is not a table");
    }

    int year = getNumberField(L, "year");
    int month = getNumberField(L, "month");
    int day = getNumberField(L, "day");
    int hour = getNumberField(L, "hour");
    int min = getNumberField(L, "min");
    int sec = getNumberField(L, "sec");
    int ms = getNumberField(L, "ms");

    //2015-11-06 18:44:59.473
    if ( sprintf(data.dat_time, "%d-%.2d-%.2d %.2d:%.2d:%.2d:%.3d", year, month, day, hour, min, sec, ms) > dat_time_buf)
        luaL_error(L, "dat_time_buf overflow");

    lua_pop(L, 1);

    //FORTS csv format for features: "code;contract;price;amount;dat_time;trade_id;Nosystem"
    printf("%s;;%f;%Iu;%s;%Iu;0\n", data.code, data.price, data.amount, data.dat_time, data.trade_id);

    return 0;
}

static struct luaL_reg ls_lib[] = {
{"OnAllTrade", forOnAllTrade},
{NULL, NULL}
};

int luaopen_quik_lua_export(lua_State *L) {
    luaL_openlib(L, "quik_lua_export", ls_lib, 0);
    return 0;
}

int main(int /*argc*/, char */*argv*/[])
{
    return 0;
}
