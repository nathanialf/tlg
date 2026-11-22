/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "AddTrackingExt" (registered at
 * 0x1d5ab8, "Add TrackingExt"): with exactly four arguments, reads the
 * first as a 64-bit id (FUN_00c8c990, -1 when absent), the second and third
 * as numbers (FUN_00c8d380, -1 when absent) and the fourth as an object
 * (FUN_00c8c290); when the id is not negative, neither number is, and the
 * object is of the class the pointer at 0x5939080 holds, hands the id, the
 * two numbers and the object to FUN_008302e0 of the record at +0x138 of the
 * game's record (0x57c9390); returns 0. */
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

struct Tracking00830b30; /* derived name; not traced */

struct Game00830b30 { /* derived name: the record at 0x57c9390 */
    u8 unknown0[0x138];
    Tracking00830b30 *tracking138; /* +0x138 */
};

extern Game00830b30 *D_57c9390;
extern Type00503fb0 *D_5939080; /* derived name: the tracked object's class */

void FUN_00c8c990(ArgumentReader00c8c290 *reader, s64 *value);              /* derived name */
void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value);            /* derived name */
void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_008302e0(Tracking00830b30 *tracking, s64 id, const float *range,
                  Object016b9108 *object); /* derived name */

// NONMATCHING: the two numbers' tests: the base compares the first with zero in memory form
// (`vxorps; vucomiss xmm0, [rbp-0xa8]; ja`) and loads the second (`vucomiss xmm1, xmm0; jb`),
// the build the other way round (written `!(x < 0)` or `x >= 0`, the same); the rest equal
int FUN_00830b30(lua_State *state) /* derived name */
{
    if (argumentCount(state) == 4) {
        s64 id = -1;
        float range[2] = {-1.0f, -1.0f};
        Object016b9108 *object = 0;
        ArgumentReader00c8c290 first(state);
        FUN_00c8c990(&first, &id);
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8d380(&second, &range[0]);
        ArgumentReader00c8c290 third(state, 2);
        FUN_00c8d380(&third, &range[1]);
        ArgumentReader00c8c290 fourth(state, 3);
        FUN_00c8c290(&fourth, &object);
        if (id >= 0 && range[0] >= 0.0f && range[1] >= 0.0f && object &&
            object->isKindOf(D_5939080))
            FUN_008302e0(D_57c9390->tracking138, id, range, object);
    }
    return 0;
}
