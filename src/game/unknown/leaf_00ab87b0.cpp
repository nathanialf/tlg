/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"
#include "tlg_hks_string.h"

/* derived names: the script C function "Ai2EvalPathCurv" (FUN_002212a0
 * registers it through FUN_00c89b70): reads its first argument as an object
 * through FUN_00c8c290 (as leaf_0031d9a0.cpp's); when it is of the type
 * D_57dad78 points to (a path), reads the second and third as numbers
 * (FUN_00c8d380), has FUN_00ab2e00 evaluate the path's curvature with them
 * into two radii (both 0 first) and pushes a table of "found" (its count),
 * "aveCurvR" and "minCurvR"; returns 1, and 0 without a path. */
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
class Path00ab87b0 : public Object016b9108 /* derived name */
{
};

extern Type00503fb0 *D_57dad78; /* derived name: the path's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value);            /* derived name */
int FUN_00ab2e00(Path00ab87b0 *path, float first, float second, float *minRadius,
                 float *averageRadius); /* derived name */

int FUN_00ab87b0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57dad78)) {
        Path00ab87b0 *path = static_cast<Path00ab87b0 *>(object);
        float first;
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8d380(&second, &first);
        float next;
        ArgumentReader00c8c290 third(state, 2);
        FUN_00c8d380(&third, &next);
        float minRadius = 0.0f;
        float averageRadius = 0.0f;
        const int found = FUN_00ab2e00(path, first, next, &minRadius, &averageRadius);
        FUN_00d91880(state, 0, 0);
        pushString(state, "found");
        pushNumber(state, float(found));
        setTable(state);
        pushString(state, "aveCurvR");
        pushNumber(state, averageRadius);
        setTable(state);
        pushString(state, "minCurvR");
        pushNumber(state, minRadius);
        setTable(state);
        return 1;
    }
    return 0;
}
