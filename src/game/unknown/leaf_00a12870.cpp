/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the script C function "PhysicsSetCondorTailPulseForceField"
 * (its help "set condor tail pulse force field"; FUN_001bd010 registers it
 * through FUN_00c87e30): with three arguments, a table first and two numbers,
 * the field of the second number's side (1 or 2) and the third's slot (1 to
 * 4) among the fields of the object at +0x8c8 of the record at +0x38 of the
 * object at 0x57c9390 (0x100 bytes a slot, 0x80 a side, the first at
 * +0x120) is set from the table by FUN_00a12cb0, FUN_00a13410 and
 * FUN_00a13970, each with 0. Returns 0. */
struct ForceField00a12870 { /* derived name */
    u8 unknown0[0x80];
};

struct ForceFields00a12870 { /* derived name */

    /* the field of a slot and a side (derived name) */
    ForceField00a12870 *field(unsigned slot, unsigned side)
    {
        return &fields[slot][side];
    }

    u8 unknown0[0x120];
    ForceField00a12870 fields[4][2]; /* +0x120 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x8c8];
    ForceFields00a12870 *unknown8c8; /* +0x8c8 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

/* derived name: whether an argument is a table or a struct (tags 5 and 12,
 * the struct's tested first: `cmp ecx, 0xc; je; cmp ecx, 5; jne`), its raw
 * tag read, false past the frame's top */
static inline bool isTable(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        return false;
    const int type = value->type & 0xf;
    return type == 12 || type == 5;
}

void FUN_00a12cb0(ForceField00a12870 *field, lua_State *state, int unknown2); /* derived name */
void FUN_00a13410(ForceField00a12870 *field, lua_State *state, int unknown2); /* derived name */
void FUN_00a13970(ForceField00a12870 *field, lua_State *state, int unknown2); /* derived name */

/* The field through field(slot, side): the indexes are extended in its
 * body, after the global and its chain are loaded (a subscript emits its
 * indexes first), so the global takes rcx and the side's offset rdx. */
int FUN_00a12870(lua_State *state) /* derived name */
{
    if (argumentCount(state) == 3 && isTable(state, 1) && isNumber(state, 2) &&
        isNumber(state, 3)) {
        const unsigned side = int(toNumber(state, 2)) - 1;
        if (side > 1)
            return 0;
        const unsigned slot = int(toNumber(state, 3)) - 1;
        if (slot > 3)
            return 0;
        ForceField00a12870 *field = D_57c9390->unknown38->unknown8c8->field(slot, side);
        FUN_00a12cb0(field, state, 0);
        FUN_00a13410(field, state, 0);
        FUN_00a13970(field, state, 0);
    }
    return 0;
}
