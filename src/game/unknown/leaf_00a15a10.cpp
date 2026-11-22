/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the script C function "PhysicsAddForceField"
 * (FUN_001bd010 registers it through FUN_00c87e30, lea at 0x1d30b1): with
 * one argument, a table, a force field built on the stack from nothing is
 * filled from the table by FUN_00a12cb0, FUN_00a13410 and FUN_00a13970 (each
 * with 1, each a success) and handed to FUN_00a02120 with the object at +0x30
 * of the record at +0x58 of the object at 0x57c9390. Returns 0. The field is
 * 32-byte aligned (`and rsp, -0x20`, four aligned `vmovaps ymm` of zero) and
 * its contents are not traced (leaf_00a12870.cpp, leaf_00a02680.cpp). */
struct alignas(32) ForceField00a15a10 { /* derived name */
    u8 unknown0[0x80];
};

struct ForceFields00a15a10; /* derived name: the object FUN_00a02120 adds the field to */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x30];
    ForceFields00a15a10 *unknown30; /* +0x30 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58; /* +0x58 */
};

extern Object057c9390 *D_57c9390;

/* derived name: whether an argument is a table or a struct (tags 5 and 12,
 * the struct's tested first), false past the frame's top
 * (leaf_00a12870.cpp's) */
static inline bool isTable(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        return false;
    const int type = value->type & 0xf;
    return type == 12 || type == 5;
}

bool FUN_00a12cb0(ForceField00a15a10 *field, lua_State *state, int unknown2);    /* derived name */
bool FUN_00a13410(ForceField00a15a10 *field, lua_State *state, int unknown2);    /* derived name */
bool FUN_00a13970(ForceField00a15a10 *field, lua_State *state, int unknown2);    /* derived name */
void FUN_00a02120(ForceFields00a15a10 *fields, const ForceField00a15a10 *field); /* derived name */

int FUN_00a15a10(lua_State *state) /* derived name */
{
    if (argumentCount(state) == 1 && isTable(state, 1)) {
        ForceField00a15a10 field = ForceField00a15a10();
        if (FUN_00a12cb0(&field, state, 1) && FUN_00a13410(&field, state, 1) &&
            FUN_00a13970(&field, state, 1))
            FUN_00a02120(D_57c9390->unknown58->unknown30, &field);
    }
    return 0;
}
