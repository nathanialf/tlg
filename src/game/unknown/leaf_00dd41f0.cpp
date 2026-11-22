/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: hksi_lua_pushfstring (FUN_00d96630) and a string made
 * from a text of known length and hash (FUN_00db9de0) */
const char *FUN_00d96630(lua_State *s, const char *format, ...);
void *FUN_00db9de0(lua_State *state, const char *text, size_t length, u32 hash);

/* hksi_luaL_where (the name from its assertion message): "<source>:<line>: "
 * of the call `level` levels below the running one pushed, the empty
 * string (its hash precomputed) when it has no line; the call timed */
// NONMATCHING: register assignment only: the base keeps the mark in r13d and reads the stack guard's
// address again at the end; the build keeps the guard's address in r13 and spills the mark (the class
// of FUN_00d96630)
void FUN_00dd41f0(lua_State *s, int level)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1a1ad982, "s != NULL", "hksi_luaL_where",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 1242);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    lua_Debug ar;
    if (hksi_lua_getstack(s, level, &ar)) {
        FUN_00d908f0(s, "Sl", &ar);
        if (ar.currentline > 0) {
            FUN_00d96630(s, "%s:%d: ", ar.short_src, ar.currentline);
            return;
        }
    }
    void *string = FUN_00db9de0(s, "", 0, 0x6b6f7265);
    HksObject *top = s->top;
    top->type = 4;
    top->value.pointer = string;
    s->top = top + 1;
}
