/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"
#include "tlg_math.h"

/* derived names: the script C function "Ai2TransformPath" (FUN_002212a0
 * registers it through FUN_00c89b70): reads its first argument as an object
 * through FUN_00c8c290 (as leaf_0031d9a0.cpp's); when it is of the type
 * D_57dad78 points to (a path), reads the second as a vector of three angles
 * (FUN_00c8edb0, as leaf_002a50a0.cpp's) and makes their rotation
 * (FUN_0020c3b0, as leaf_00e7fd90.cpp's), reads the third as a vector and
 * hands the path, the rotation and that vector's three floats to
 * FUN_00519da0. Returns 0. */
struct ArgumentReader00c8c290 { /* derived name */

    /* a reader at an argument of the frame (0 the first), its index taken
     * from the top: the argument less the count of arguments */
    explicit ArgumentReader00c8c290(lua_State *state_, int argument = 0)
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

/* derived name: an object of D_57dad78's type, a path (leaf_0031d9a0.cpp) */
class Path00ab82c0 : public Object016b9108 /* derived name */
{
};

extern Type00503fb0 *D_57dad78; /* derived name: the path's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8edb0(ArgumentReader00c8c290 *reader, Float4A *vector);         /* derived name */
void FUN_0020c3b0(Float4A *rotation, float x, float y, float z);            /* derived name */
void FUN_00519da0(Path00ab82c0 *path, const Float4A *rotation, float x, float y,
                  float z); /* derived name */

int FUN_00ab82c0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57dad78)) {
        Path00ab82c0 *path = static_cast<Path00ab82c0 *>(object);
        Float4A angles;
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8edb0(&second, &angles);
        Float4A rotation;
        FUN_0020c3b0(&rotation, angles.x, angles.y, angles.z);
        Float4A offset;
        ArgumentReader00c8c290 third(state, 2);
        FUN_00c8edb0(&third, &offset);
        FUN_00519da0(path, &rotation, offset.x, offset.y, offset.z);
    }
    return 0;
}
