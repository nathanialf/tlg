/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "CustomWaterTarget_DrawDebugMesh"
 * (registered at 0x9007a4 with its usage "CustomWaterTarget_DrawDebugMesh(
 * debugMesh, waterTarget)"): with at least two arguments, reads the first
 * and the second as objects through FUN_00c8c290 (as leaf_00ab7dc0.cpp's);
 * when the first is of the class the pointer at 0x59385b8 holds (the debug
 * mesh's, leaf_008f3440.cpp) and the second of the class at 0x581fa40, pushes
 * true and returns 1; 0 otherwise. Nothing is drawn in this build. */
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

extern Type00503fb0 *D_59385b8; /* derived name: the debug mesh's class */
extern Type00503fb0 *D_581fa40; /* derived name: the water target's class */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

// NONMATCHING: register assignment only: the base keeps the result in r14d (zeroed at entry
// and after the first read, held across the second call) and the guard in r15, the build
// zeroes eax on each path
int FUN_008f3510(lua_State *state) /* derived name */
{
    int results = 0;
    if (argumentCount(state) >= 2) {
        Object016b9108 *object;
        ArgumentReader00c8c290 mesh(state);
        FUN_00c8c290(&mesh, &object);
        if (object && object->isKindOf(D_59385b8)) {
            ArgumentReader00c8c290 target(state, 1);
            FUN_00c8c290(&target, &object);
            if (object && object->isKindOf(D_581fa40)) {
                pushBoolean(state, true);
                results = 1;
            }
        }
    }
    return results;
}
