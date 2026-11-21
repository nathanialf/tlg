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

/* derived name: whether a value lies between two bounds, both included */
static inline bool isInRange(float value, float min, float max)
{
    return value <= max && value >= min;
}

/* derived names: the script C function "IsinAABB" (FUN_002212a0 registers
 * it through FUN_00c89b70, lea at 0x222250): reads its first three
 * arguments as vectors (FUN_00c8edb0), a point, a box's centre and its size,
 * and pushes whether the point lies in the box (each axis within half the
 * size of the centre, the tests in x, y, z order); returns 1. */
int FUN_002a5a90(lua_State *state) /* derived name */
{
    Float4A point;
    ArgumentReader00c8edb0 pointReader(state, 0);
    FUN_00c8edb0(&pointReader, &point);
    Float4A centre;
    ArgumentReader00c8edb0 centreReader(state, 1);
    FUN_00c8edb0(&centreReader, &centre);
    Float4A size;
    ArgumentReader00c8edb0 sizeReader(state, 2);
    FUN_00c8edb0(&sizeReader, &size);
    const float minX = centre.x - 0.5f * size.x;
    const float maxX = centre.x + 0.5f * size.x;
    const float minY = centre.y - 0.5f * size.y;
    const float maxY = centre.y + 0.5f * size.y;
    const float minZ = centre.z - 0.5f * size.z;
    const float maxZ = centre.z + 0.5f * size.z;
    pushBoolean(state, isInRange(point.x, minX, maxX) && isInRange(point.y, minY, maxY) &&
                           isInRange(point.z, minZ, maxZ));
    return 1;
}
