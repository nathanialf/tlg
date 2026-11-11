/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "PhysicsCondorStateGetNumSpearInfo"
 * ("get num spearinfo", registered through FUN_00c87e30 at 0x1d3125): pushes
 * the int at +0x158 of the record at +0x68 of the record at +0x38 of the
 * record at +0x108 of the object at 0x57c9390 as a number, and returns 1.
 * The records' types are not traced. */
struct Member057c9390_108_38_68 { /* derived name */
    u8 unknown0[0x158];
    int unknown158; /* +0x158: the count */
};

struct Member057c9390_108_38 { /* derived name */
    u8 unknown0[0x68];
    Member057c9390_108_38_68 *unknown68; /* +0x68 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_108_38 *unknown38; /* +0x38 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: greedy's assignment, as FUN_001b1010's: the base gives the object at 0x57c9390's chain or the spell a different register from the stack top than the build does (rax and rcx, or rax and rcx with rdx, swapped); the instructions are the base's but the order of the result's mov
int FUN_00a15c40(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.number = D_57c9390->unknown108->unknown38->unknown68->unknown158;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
