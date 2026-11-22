/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: the script C function "CondorPathGenSetCrossInfo"
 * (FUN_002212a0 registers it through FUN_00c89b70): reads its first
 * argument as an object through FUN_00c8c290; when it is of the type
 * D_57cc6c8 points to (or one derived from it: Object016a8430's,
 * leaf_002ef8b0.cpp), takes its path generator (the counted reference at
 * +0x6d0, the getter's copy dropped at once) and sets the generator's int
 * at +0x5e4 from the second argument (FUN_00c8d080) and its float at +0x5e8
 * from the third (FUN_00c8d380). Returns 0. */
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

class PathGen003cbaf0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x5e4 - 0x24];
    int crossInfo5e4;   /* +0x5e4 */
    float crossInfo5e8; /* +0x5e8 */
};

class Condor003cbaf0 : public Object016b9108 /* derived name */
{
  public:
    /* the path generator, a counted reference to it */
    Ref00503fb0<PathGen003cbaf0> pathGen() const
    {
        return pathGen6d0;
    }

    u8 unknown24[0x6d0 - 0x24];
    Ref00503fb0<PathGen003cbaf0> pathGen6d0; /* +0x6d0 */
};

extern Type00503fb0 *D_57cc6c8; /* derived name: the condor's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8d080(ArgumentReader00c8c290 *reader, long *value);             /* derived name */
void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value);            /* derived name */

int FUN_003cbaf0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57cc6c8)) {
        PathGen003cbaf0 *gen = static_cast<Condor003cbaf0 *>(object)->pathGen().get();
        long cross = 0;
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8d080(&second, &cross);
        gen->crossInfo5e4 = cross;
        ArgumentReader00c8c290 third(state, 2);
        FUN_00c8d380(&third, &gen->crossInfo5e8);
    }
    return 0;
}
