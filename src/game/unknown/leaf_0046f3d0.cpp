/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_hks.h"

/* derived names: a script C function: reads its first argument as an
 * object through FUN_00c8c290 with a reader of the frame (as
 * leaf_0046a860.cpp's); when it is a node of the type D_5939080 points to
 * (or one derived from it) whose components include one of the type
 * D_57d4a68 points to, pushes the first such component's flag at +0x9dc
 * and returns 1; else returns 0 (no results). */
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
extern Type00503fb0 *D_57d4a68; /* derived name: the component's type */

struct Component0046f3d0 : Component00503fb0 { /* derived name */
    u8 unknown8c[0x950];
    bool flag9dc; /* +0x9dc */
};

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

// NONMATCHING: 68/88 at the base's 308 bytes. The count's drop is the base's (`lock dec dword ptr
// [r14]`, findComponent's by-hand form). First difference: the return's 0 is made in the entry
// (`xor eax, eax` before `test r13, r13`) and serves the not-kind exit too, where the base makes it
// in the not-kind block (0x46f45d, the null object's branch joining it) and again before the drop
// (`xor eax, eax; lock dec`); the type walk's registers follow (round 569D)
int FUN_0046f3d0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5939080)) {
        Component0046f3d0 *component = static_cast<Component0046f3d0 *>(
            static_cast<Object016b85e0 *>(object)->findComponent(D_57d4a68));
        if (component) {
            pushBoolean(state, component->flag9dc);
            return 1;
        }
    }
    return 0;
}
