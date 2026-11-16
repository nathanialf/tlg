/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the script C function "SaveOldData" (FUN_001bd010
 * registers it, lea at 0x1db4e2): when it is given an argument, reads it as
 * an object through FUN_00c8c290 with a reader of the frame (as
 * leaf_0046bc50.cpp's) and hands it to FUN_00a26680 with the record at
 * +0x108 of the object the pointer at 0x57c9390 holds; returns 0 (no
 * results). The C function's own name is unknown. */
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

struct Record057c9390_108; /* derived name */
struct Object001b2f20;     /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Record057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object001b2f20 **object); /* derived name */
void FUN_00a26680(Record057c9390_108 *record, Object001b2f20 *object);      /* derived name */

int FUN_001b2f20(lua_State *state) /* derived name */
{
    if (argumentCount(state) > 0) {
        ArgumentReader00c8c290 reader(state);
        Object001b2f20 *object = 0;
        FUN_00c8c290(&reader, &object);
        FUN_00a26680(D_57c9390->unknown108, object);
    }
    return 0;
}
