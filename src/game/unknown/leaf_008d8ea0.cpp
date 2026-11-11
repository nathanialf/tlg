/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "MSC_GetTatooLevel" (FUN_001db8b0
 * registers it through FUN_00c87e30, lea at 0x1de219, signature string
 * "MSC_GetTatooLevel()"): pushes the float at +0x50 of the record at +0x38 of
 * the record at +0x108 of the object the pointer at 0x57c9390 holds as a
 * number and returns one result. The C function's own name is unknown. */
struct Member057c9390_108_38 { /* derived name */
    u8 unknown0[0x50];
    float unknown50;
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_108_38 *unknown38;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: greedy's assignment: the base gives the chain from the pointer at 0x57c9390 rax and
// the stack top rcx, the compile the reverse; every instruction else equal (the value computed
// before the top in the source compiles the same; the sibling FUN_001b0880, one load shorter, is
// equal)
int FUN_008d8ea0(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.number = D_57c9390->unknown108->unknown38->unknown50;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
