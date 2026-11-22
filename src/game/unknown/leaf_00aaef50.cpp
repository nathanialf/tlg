/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function
 * "Ai2InterestSystem_OverwriteGazeSpeed" (FUN_002212a0 registers it through
 * FUN_00c89b70): reads its first argument as an object through FUN_00c8c290
 * (as leaf_0031d9a0.cpp's); when it is of the type D_5829020 points to (or
 * one derived from it), reads the second and third as numbers (FUN_00c8d380,
 * 0 and -1 when absent) into the floats at +0x84 and +0x88 of the object at
 * its +0x138 and sets the int at +0x8c to 0 (FUN_00aaf0b0 resets them).
 * Returns 0. */
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

/* derived name: the object at +0x138 of an object of D_5829020's type */
struct System00aaef50 {
    /* the two speeds stored with the int after them cleared (FUN_00aaf0b0
     * stores -1 and -1) */
    void overwriteGazeSpeed(float first, float next) /* derived name */
    {
        unknown84 = first;
        unknown88 = next;
        unknown8c = 0;
    }

    u8 unknown0[0x84];
    float unknown84; /* +0x84 */
    float unknown88; /* +0x88 */
    int unknown8c;   /* +0x8c */
};

/* derived name: an object of D_5829020's type (leaf_002c40a0.cpp) */
class Object00aaef50 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x114];
    System00aaef50 *unknown138; /* +0x138 */
};

extern Type00503fb0 *D_5829020; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value);            /* derived name */

int FUN_00aaef50(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5829020)) {
        Object00aaef50 *owner = static_cast<Object00aaef50 *>(object);
        float first = 0.0f;
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8d380(&second, &first);
        float next = -1.0f;
        ArgumentReader00c8c290 third(state, 2);
        FUN_00c8d380(&third, &next);
        owner->unknown138->overwriteGazeSpeed(first, next);
    }
    return 0;
}
