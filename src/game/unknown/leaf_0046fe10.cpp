/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Soldier_SomeOne_HasMirrorShield"
 * (registered through FUN_00c89b70 at 0x22357a): pushes the boolean whether
 * the pointer at +0x148 of the record at +0x900 of the record at +0x38 of the
 * object at 0x57c9390 is set, and returns 1. The records' types are not
 * traced. */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x148];
    void *unknown148; /* +0x148 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: greedy's assignment, as FUN_001b1010's: the base gives the stack top rcx and the boolean eax, the build rax and ecx; every instruction else equal
int FUN_0046fe10(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.boolean = D_57c9390->unknown38->unknown900->unknown148 != 0;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
