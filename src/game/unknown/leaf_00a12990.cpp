/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object01343880.h"
#include "tlg_hks.h"

/* derived names: the script C function "PhysicsRestoreBodyTransform"
 * (FUN_001bd010 registers it through FUN_00c87e30): with exactly one
 * argument, read as an object through FUN_00c8c290 (as leaf_0031d9a0.cpp's),
 * when it is of the type D_5946a58 points to (the component FUN_009f5540
 * looks for), sets the position and the rotation of its node (+0x28) from
 * the ones it saved at +0x110 and +0x120. Returns 0. */
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

/* derived name: a component of D_5946a58's type: the node's position and
 * rotation saved at +0x110 and +0x120 */
class Component00a12990 : public Object01343880 /* derived name */
{
  public:
    u8 unknown34[0xdc];
    Float4A position; /* +0x110 (derived name) */
    Float4A rotation; /* +0x120 (derived name) */
};

extern Type00503fb0 *D_5946a58; /* derived name: the component's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

int FUN_00a12990(lua_State *state) /* derived name */
{
    if (argumentCount(state) == 1) {
        Object016b9108 *object = 0;
        ArgumentReader00c8c290 reader(state);
        FUN_00c8c290(&reader, &object);
        if (object && object->isKindOf(D_5946a58)) {
            Component00a12990 *component = static_cast<Component00a12990 *>(object);
            Object016b85e0 *node = static_cast<Object016b85e0 *>(component->unknown28);
            node->setPosition(component->position);
            node->setRotation(component->rotation);
        }
    }
    return 0;
}
