/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_hks.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the script C function
 * "Soldier_SoldierHelmet_TractionInvalidArea_Leave" (FUN_002212a0 registers
 * it through FUN_00c89b70, lea at 0x223538): reads its first argument as an
 * object through FUN_00c8c290 with a reader of the frame (as
 * leaf_0046bc50.cpp's); when it is a node of the type D_5939080 points to
 * (or one derived from it), each of its components of the type D_581b510
 * points to whose name is D_57d5838 has its second name (+0x58) made
 * D_57d5840; returns 0 (no results). The C function's own name is unknown. */
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
extern Type00503fb0 *D_581b510; /* derived name */
extern Name D_57d5838;          /* derived name */
extern Name D_57d5840;          /* derived name */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

// The reader count's drops stay apart before their successor (`lock dec dword`, one jumping, one falling
// in) by the tail-merge rule (tools/patches/llvm-3.7.1-tailmerge-01-narrow-atomic-ends-tail.patch, D96).
int FUN_0046f980(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5939080)) {
        Object016b85e0 *node = static_cast<Object016b85e0 *>(object);
        unsigned next = 0;
        for (Component00503fb0 *component = node->findComponent(D_581b510, next); component;
             component = node->findComponent(D_581b510, next)) {
            if (component->name == D_57d5838)
                component->name58 = D_57d5840;
        }
    }
    return 0;
}
