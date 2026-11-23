/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: luaL_getmetatable (FUN_00dd4020) and Lua's lua_rawequal by
 * its operands (FUN_00db79f0) */
void FUN_00dd4020(lua_State *s, const char *name);
int FUN_00db79f0(lua_State *state, const HksObject *a, const HksObject *b);

/* derived names: the value at an index, an argument (from 1) or one from
 * the stack's top (from -1), null outside the frame; whether it is a full
 * (tag 7) or a light (tag 2) userdata, and its userdata */
inline const HksObject *valueAt(lua_State *state, int index)
{
    if (index > 0) {
        const HksObject *value = state->base + (index - 1);
        return value < state->top ? value : 0;
    }
    const HksObject *value = state->top + index;
    return value >= state->base ? value : 0;
}

inline bool isUserdataAt(lua_State *state, int index)
{
    if (!(state->base + (index - 1) < state->top))
        return false;
    const HksObject *value = valueAt(state, index);
    const int type = value->type & 0xf;
    return type == 7 || type == 2;
}

inline void *userdataAt(lua_State *state, int index)
{
    const HksObject *value = valueAt(state, index);
    if (!value)
        return 0;
    const int type = value->type & 0xf;
    if (type == 7)
        return static_cast<HksUserdata *>(value->value.pointer) + 1;
    if (type == 2)
        return value->value.pointer;
    return 0;
}

/* luaL_checkudata (the name from its assertion message): the first
 * argument's userdata when its metatable is the registry's under `name`,
 * else the argument error naming the type; the call timed */
// NONMATCHING: the base keeps the argument's slot as a select of null before the type load (`cmp;
// cmovb; mov eax, [rax]`) after its own top test, and joins the two stack tests of the raw compare as
// one `or` of flags; the build folds the select into the load
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 440 at the
 * link, over its threshold of 175: one signature changes no row) */
void *FUN_00dd3dd0(lua_State *s, const char *name)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1f092432, "s != NULL", "luaL_checkudata",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 446);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    if (isUserdataAt(s, 1) && getMetatable(s, 1)) {
        FUN_00dd4020(s, name);
        const HksObject *a = valueAt(s, -1);
        const HksObject *b = valueAt(s, -2);
        const int equal = a == 0 || b == 0 ? 0 : FUN_00db79f0(s, a, b);
        pop(s, 2);
        if (equal)
            return userdataAt(s, 1);
    }
    FUN_00dd38c0(s, 1, name);
    return 0;
}
