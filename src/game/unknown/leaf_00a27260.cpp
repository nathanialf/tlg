/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: the script C function "Treasure_SystemInit" (registered at
 * 0xa2713a): with one argument, an object of D_5939080's type (read through
 * FUN_00c8c290, as leaf_00469710.cpp's), the record FUN_00c57870 finds in it
 * for the key at 0x581cb60 goes into the counted reference at +0x28 of the
 * treasure system the pointer at 0x5827190 holds. Returns 0. */
struct ArgumentReader00c8c290 { /* derived name */

    /* a reader at an argument of the frame (0 the first), its index taken
     * from the top: the argument less the count of arguments */
    explicit ArgumentReader00c8c290(lua_State *state_, int argument = 0)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = argument - argumentCount(state_);
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

class Record00a27260 : public Object016b9108 /* derived name */
{
};

struct TreasureSystem05827190 { /* derived name */
    u8 unknown0[0x28];
    AtomicRef0045c470<Record00a27260> unknown28; /* +0x28 */
};

extern TreasureSystem05827190 *D_5827190;
extern Type00503fb0 *D_5939080; /* derived name: the object's type */
extern u64 D_581cb60;           /* derived name: the key looked up */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object);  /* derived name */
Record00a27260 *FUN_00c57870(Object016b9108 *object, u64 key, int unknown2); /* derived name */

int FUN_00a27260(lua_State *state) /* derived name */
{
    if (argumentCount(state) == 1) {
        Object016b9108 *object = 0;
        ArgumentReader00c8c290 reader(state);
        FUN_00c8c290(&reader, &object);
        if (object && object->isKindOf(D_5939080))
            D_5827190->unknown28.set(FUN_00c57870(object, D_581cb60, 0));
    }
    return 0;
}
