/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2DispPath" (FUN_002212a0 registers
 * it through FUN_00c89b70, lea at 0x223afa): reads its first argument as an
 * object through FUN_00c8c290 (as leaf_0031d9a0.cpp's); when it is of the
 * type D_57dad78 points to (Object016ab1d8's, a path), returns 1, and 0
 * otherwise; nothing is pushed and nothing else is done with it. */
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
class Path00ab8450 : public Object016b9108 /* derived name */
{
};

extern Type00503fb0 *D_57dad78; /* derived name: the path's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

int FUN_00ab8450(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57dad78))
        return 1;
    return 0;
}
