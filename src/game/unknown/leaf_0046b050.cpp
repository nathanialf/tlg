/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Soldier_SetEyeLight" (FUN_002212a0
 * registers it through FUN_00c89b70, lea at 0x2231de): reads its first
 * argument as an object through FUN_00c8c290 with a reader of the frame (as
 * leaf_0046bc50.cpp's); when it is of the type D_5939080 points to (or one
 * derived from it) and the global's member at +0x38 has its record at
 * +0x900, hands the object to FUN_0048af30 with the truth of the second
 * argument and 0; returns 0 (no results). The C function's own name is
 * unknown. */
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

struct Record057c9390_38_900; /* derived name */

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Record057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;
extern Type00503fb0 *D_5939080; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_0048af30(Object016b9108 *object, bool on, int unknown);            /* derived name */

// NONMATCHING: the second argument's truth: the base keeps the slot a select of null past the
// top (`cmovae rcx, rax; jae`) and reads the tag and the boolean through it, the build folds
// the select into the branch and reads off the base (`[rax+0x18]`); the rest is the base's
int FUN_0046b050(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5939080)) {
        const bool on = toBoolean(state, 2);
        if (D_57c9390->unknown38->unknown900)
            FUN_0048af30(object, on, 0);
    }
    return 0;
}
