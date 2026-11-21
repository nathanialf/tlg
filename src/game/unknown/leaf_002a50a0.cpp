/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_hks.h"
#include "tlg_math.h"

/* derived names: a reader of the frame's arguments for FUN_00c8edb0 (as
 * leaf_00e7de80.cpp's), its index the argument's offset from the first
 * less the count of arguments. */
struct ArgumentReader00c8edb0 { /* derived name */

    ArgumentReader00c8edb0(lua_State *state_, int argument)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = argument - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                                 sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

void FUN_00c8edb0(ArgumentReader00c8edb0 *reader, Float4A *vector); /* derived name */

/* derived names: the script C function "Ai2GetDistanceXZ" (FUN_002212a0
 * registers it through FUN_00c89b70, lea at 0x2221e2): reads its first two arguments as
 * vectors (FUN_00c8edb0) and pushes the distance between them in the x-z
 * plane; returns 1. */
int FUN_002a50a0(lua_State *state) /* derived name */
{
    Float4A from;
    ArgumentReader00c8edb0 fromReader(state, 0);
    FUN_00c8edb0(&fromReader, &from);
    Float4A to;
    ArgumentReader00c8edb0 toReader(state, 1);
    FUN_00c8edb0(&toReader, &to);
    const float dx = to.x - from.x;
    const float dz = to.z - from.z;
    pushNumber(state, sqrtf(dx * dx + dz * dz));
    return 1;
}
