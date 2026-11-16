/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2RegisterNavmesh" (FUN_002212a0
 * registers it through FUN_00c89b70, lea at 0x222316): reads its
 * first argument as an object through FUN_00c8c290 with a reader of the
 * frame (as leaf_0046bc50.cpp's), 0 returned without one; when it is of the
 * type D_581fe00 points to (or one derived from it) reads its second
 * argument through FUN_00c8d080 (an 8-byte value) and stores the object in
 * the slot of that number (0, 1 or 2; another number stores nothing) of the
 * three at +0x28 of the record at +0x8c0 of the global's member at +0x38;
 * returns 1. The C function's own name is unknown. */
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

struct Navmeshes003e7120 { /* derived name */
    Object016b9108 *slots[3];
};

struct Record003e7120 { /* derived name */
    u8 unknown0[0x28];
    Navmeshes003e7120 *navmeshes; /* +0x28 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x8c0];
    Record003e7120 *unknown8c0; /* +0x8c0 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;
extern Type00503fb0 *D_581fe00; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8d080(ArgumentReader00c8c290 *reader, long *value);             /* derived name */

int FUN_003e7120(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (!object)
        return 0;
    if (object->isKindOf(D_581fe00)) {
        Object016b9108 *navmesh = object;
        long slot;
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8d080(&second, &slot);
        Member057c9390_38 *member = D_57c9390->unknown38;
        switch (slot) {
        case 0:
            member->unknown8c0->navmeshes->slots[0] = navmesh;
            break;
        case 1:
            member->unknown8c0->navmeshes->slots[1] = navmesh;
            break;
        case 2:
            member->unknown8c0->navmeshes->slots[2] = navmesh;
            break;
        }
    }
    return 1;
}
