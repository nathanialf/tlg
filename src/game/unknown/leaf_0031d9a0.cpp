/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2MakePath" (FUN_002212a0
 * registers it through FUN_00c89b70): reads its first argument as an object
 * through FUN_00c8c290 and, when it is of the type D_57cc6c8 points to (or
 * one derived from it: Object016a8430's, leaf_002ef8b0.cpp), its second into
 * the same variable; when that is of the type D_57dad78 points to
 * (Object016ab1d8's, leaf_00511380.cpp), reads the third and then the fourth
 * argument as numbers (FUN_00c8d380) into one float and hands the path to
 * FUN_0051afa0 with 0, 0 and that float (the fourth argument's). Returns 0. */
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

/* derived name: an object of D_57dad78's type, a path */
class Path0031d9a0 : public Object016b9108 /* derived name */
{
};

extern Type00503fb0 *D_57cc6c8; /* derived name: the condor's type */
extern Type00503fb0 *D_57dad78; /* derived name: the path's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object);     /* derived name */
void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value);                /* derived name */
void FUN_0051afa0(Path0031d9a0 *path, int unknown1, int unknown2, float value); /* derived name */

int FUN_0031d9a0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57cc6c8)) {
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8c290(&second, &object);
        if (object && object->isKindOf(D_57dad78)) {
            Path0031d9a0 *path = static_cast<Path0031d9a0 *>(object);
            float value = 0.0f;
            ArgumentReader00c8c290 third(state, 2);
            FUN_00c8d380(&third, &value);
            ArgumentReader00c8c290 fourth(state, 3);
            FUN_00c8d380(&fourth, &value);
            FUN_0051afa0(path, 0, 0, value);
        }
    }
    return 0;
}
