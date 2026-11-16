/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function
 * "AnimationEnableCollectConditionResult" (FUN_001bd010 registers it, lea at
 * 0x1c4524): reads its first argument as an object through FUN_00c8c290
 * with a reader of the frame (as leaf_0046bc50.cpp's); when it is of the
 * type D_57db090 points to (or one derived from it) reads its second
 * argument through FUN_00c8c570 with a reader at that argument (0 given as
 * the third value) into the object's int at +0x4de0; returns 0 (no
 * results). The C function's own name is unknown. */
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

class Object005f3280 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x4dbc];
    int unknown4de0; /* +0x4de0 */
};

extern Type00503fb0 *D_57db090; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8c570(ArgumentReader00c8c290 *reader, int *value, int unknown); /* derived name */

int FUN_005f3280(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57db090)) {
        Object005f3280 *target = static_cast<Object005f3280 *>(object);
        int value;
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8c570(&second, &value, 0);
        target->unknown4de0 = value;
    }
    return 0;
}
