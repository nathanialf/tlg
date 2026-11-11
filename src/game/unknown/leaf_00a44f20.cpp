/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Sound_SetDebugFlag" (FUN_00a44ab0
 * registers it through FUN_00c87e30, lea at 0xa44b12, signature string
 * "Sound_SetDebugFlag(Bool flg)"): stores the truth of its first argument (an
 * absent argument or nil false, a boolean its value, anything else true; the
 * type tag the low four bits) as the int at +0x9c of the object the pointer at
 * 0x5827b50 holds, sets the int at +0x98 to 1, and returns 0 (no results).
 * The C function's own name is unknown. */
struct Object05827b50 { /* derived name */
    u8 unknown0[0x98];
    int unknown98; /* +0x98 */
    int unknown9c; /* +0x9c: the flag */
};

extern Object05827b50 *D_5827b50;

// NONMATCHING: greedy's assignment: the base's selected pointer (`cmovae rax, rcx; jae`)
// and the type in edx with the flag in cl are here in rcx, eax and ecx, two bytes longer;
// the select and the branch on the range test are the base's (the type read under the
// range test, not a null test of the pointer, which gives `test rcx, rcx; je`).
int FUN_00a44f20(lua_State *state) /* derived name */
{
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool flag = false;
    if (type != 0) {
        flag = true;
        if (type == 1)
            flag = value->value.boolean != 0;
    }
    D_5827b50->unknown9c = flag;
    D_5827b50->unknown98 = 1;
    return 0;
}
