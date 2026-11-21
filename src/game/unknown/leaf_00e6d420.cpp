/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function the VM knows as
 * "UpdateWorldTransform" (the name FUN_00e6e060 gives it through
 * FUN_00dd6ba0, lea at 0xe6e748): with an argument, reads it as an object
 * through FUN_00c8c290 with a reader of the frame (as leaf_0046bc50.cpp's);
 * a node of the type D_5939080 points to (or one derived from it) is
 * handed to FUN_00c59ef0 (its parents first, then its own slot 7) under the
 * world's reader lock. Returns 0 (no results). */
struct ArgumentReader00c8c290 { /* derived name */

    explicit ArgumentReader00c8c290(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index =
            -(int)((unsigned long)((char *)state_->top - (char *)state_->base) / sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

extern Type00503fb0 *D_5939080; /* derived name: the node's type */

class Node00c59ef0; /* leaf_00c59ef0.cpp */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c59ef0(Node00c59ef0 *node);                                      /* derived name */

/* derived name: the object the frame's first argument holds, read through
 * FUN_00c8c290 (as leaf_0046fb90.cpp's) */
static inline Object016b9108 *objectArgument(lua_State *state)
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    return object;
}

int FUN_00e6d420(lua_State *state) /* derived name */
{
    if (argumentCount(state) > 0) {
        Object016b9108 *object = objectArgument(state);
        if (object && object->isKindOf(D_5939080)) {
            D_5938c40->world->lockRead();
            FUN_00c59ef0(reinterpret_cast<Node00c59ef0 *>(object));
            D_5938c40->world->unlockRead();
        }
    }
    return 0;
}
