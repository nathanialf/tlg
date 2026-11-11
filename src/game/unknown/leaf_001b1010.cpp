/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "TricoGame_IsInGame" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db226, signature string
 * "isInGame= IsInGame()"): pushes bit 1 of the int at +0x184 of the object the
 * pointer at 0x57c9390 holds, as a bool (`bextr` of one bit), and returns one
 * result. The C function's own name is unknown. */
struct Object057c9390 { /* derived name */
    u8 unknown0[0x184];
    unsigned unknown184;
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: greedy's assignment: the base gives the pointer at 0x57c9390 rax, the bextr control
// edx and the stack top rcx, the compile rcx, eax and rdx; every instruction else equal (the value
// computed before the top in the source compiles the same; the sibling FUN_001b0880 with a plain
// float is equal)
int FUN_001b1010(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.boolean = (D_57c9390->unknown184 & 2) != 0;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
