/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_hks_string.h"

/* derived names: the script C function "Soldier_GetLastThrowerName"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x22312e): reads
 * its first argument as an object through FUN_00c8c290 with a reader of the
 * frame (as leaf_0046bc50.cpp's); when it is of the type D_5939080 points to
 * (or one derived from it), finds the entry of the list at +0x900 of the
 * object at +0x38 of D_57c9390 whose Name at +0x398 is the object's, and
 * pushes the string of the Name of the object at the entry's +0x28 (from
 * the name table with its length, FUN_013aacc0); else pushes nil. Returns
 * 1. The C function's own name is unknown. */
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

struct Soldier00469710 /* derived name */
{
    u8 unknown0[0x28];
    Object016b9108 *lastThrower; /* +0x28 */
    u8 unknown30[0x368];
    Name unknown398; /* +0x398 */
};

struct Soldiers00469710 /* derived name */
{
    u8 unknown0[0x18];
    Soldier00469710 **entries; /* +0x18 */
    int count;                 /* +0x20 */
};

struct World00469710 /* derived name */
{
    u8 unknown0[0x900];
    Soldiers00469710 *soldiers; /* +0x900 */
};

struct Game00469710 /* derived name */
{
    u8 unknown0[0x38];
    World00469710 *world; /* +0x38 */
};

extern Game00469710 *D_57c9390; /* derived name */
extern Type00503fb0 *D_5939080; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

int FUN_00469710(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5939080)) {
        Soldiers00469710 *soldiers = D_57c9390->world->soldiers;
        for (int i = 0; i < soldiers->count; ++i) {
            Soldier00469710 *soldier = soldiers->entries[i];
            if (soldier->unknown398 == object->name) {
                const NameTableEntry017ac870 &entry = D_17ac870[soldier->lastThrower->name.index];
                FUN_013aacc0(state, entry.string0, entry.length14);
                return 1;
            }
        }
    }
    pushNil(state);
    return 1;
}
