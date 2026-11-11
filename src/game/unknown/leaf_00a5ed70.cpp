/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Spell_GetParam" ("Bool,Number
 * Spell_GetParam()", registered through FUN_00c87e30 at 0xa5e153): pushes the
 * byte at +0x9 of the object the pointer at 0x5827ee0 holds as a boolean and
 * the float at +0x4c as a number, and returns 2. The object's type is not
 * traced beyond these. */
struct Object05827ee0 { /* derived name */
    u8 unknown0[9];
    bool unknown9; /* +0x9: the Bool */
    u8 unknowna[0x42];
    float unknown4c; /* +0x4c: the Number */
};

extern Object05827ee0 *D_5827ee0;

// NONMATCHING: greedy's assignment, as FUN_001b1010's: the base gives the object at 0x57c9390's chain or the spell a different register from the stack top than the build does (rax and rcx, or rax and rcx with rdx, swapped); the instructions are the base's but the order of the result's mov
int FUN_00a5ed70(lua_State *state) /* derived name */
{
    Object05827ee0 *spell = D_5827ee0;
    HksObject *top = state->top;
    top->value.boolean = spell->unknown9;
    top->type = 1;
    state->top = top + 1;
    top = state->top;
    top->value.number = spell->unknown4c;
    top->type = 3;
    state->top = top + 1;
    return 2;
}
