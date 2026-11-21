/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Soldier_KeepEntityOfDrawParts"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2231c8): reads
 * its first two arguments as objects through FUN_00c8c290 (readers of the
 * frame, as leaf_002dab30.cpp's), the second only when the first is of the
 * type D_5939080 points to (or one derived from it); when both are, hands
 * them to FUN_0048e8d0 with the record at +0x900 of the global's member at
 * +0x38, when there is one. Returns 0. */
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

/* derived name: an object of that type, a soldier (the C functions'
 * prefix); its own members are not read here */
class Soldier0046af10 : public Object016b9108 /* derived name */
{
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
extern Type00503fb0 *D_5939080; /* derived name: the objects' type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_0048e8d0(Record057c9390_38_900 *record, Soldier0046af10 *soldier,
                  Soldier0046af10 *other); /* derived name */

/* derived name: the object an argument of the frame holds, read through
 * FUN_00c8c290 (the reader's and the object's slots end here: the second
 * reader takes them) */
static inline Object016b9108 *objectArgument(lua_State *state, int argument)
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state, argument);
    FUN_00c8c290(&reader, &object);
    return object;
}

int FUN_0046af10(lua_State *state) /* derived name */
{
    Object016b9108 *object = objectArgument(state, 0);
    if (object && object->isKindOf(D_5939080)) {
        Object016b9108 *other = objectArgument(state, 1);
        if (other && other->isKindOf(D_5939080)) {
            if (Record057c9390_38_900 *record = D_57c9390->unknown38->unknown900)
                FUN_0048e8d0(record, static_cast<Soldier0046af10 *>(object),
                             static_cast<Soldier0046af10 *>(other));
        }
    }
    return 0;
}
