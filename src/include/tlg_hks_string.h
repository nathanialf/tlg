/* Havok Script: pushing a C string, as the game's script C functions inline
 * it (0xe70540 "GetDataPath", 0xa45c20 "Sound_GetCSV", 0x1b58b0). */
#ifndef TLG_HKS_STRING_H
#define TLG_HKS_STRING_H

#include "tlg_hks.h"

/* derived name: pushes a string of a given length (FUN_013aacc0; Lua's
 * lua_pushlstring by its arguments) */
void FUN_013aacc0(lua_State *state, const char *string, size_t length);

/* derived name: lua_pushstring as Lua writes it: nil (tag 0) on the stack's
 * top for a null string, else the string with its length from strlen */
inline void pushString(lua_State *state, const char *string)
{
    if (string == 0) {
        HksObject *top = state->top;
        top->type = 0;
        state->top = top + 1;
    } else {
        FUN_013aacc0(state, string, strlen(string));
    }
}

#endif
