/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: a reader of the frame's first argument for FUN_00c91140
 * (as leaf_003e7260.cpp's). */
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

/* derived names: the object at 0x5827190 (as leaf_001b2ff0.cpp's): an array
 * of Names at +0x50 that the treasure functions search. */
struct Object05827190 { /* derived name */

    /* whether the name is one of the array's (the name taken by value: its
     * copy's reference raised before the search, dropped after) */
    bool has(Name name) const /* derived name */
    {
        return names.indexOf(name) >= 0;
    }

    u8 unknown0[0x50];
    Array05943280<Name> names; /* +0x50 */
};

extern Object05827190 *D_5827190;

void FUN_00c91140(ArgumentReader00c8c290 *reader, Name *name); /* derived name */

/* derived names: the script C function "IsTreasureEquipmentHandAblilities" (FUN_002212a0 registers it
 * through FUN_00c89b70, lea at 0x22223a; the same
 * body as FUN_002a5810): reads its first argument as a
 * Name (FUN_00c91140) and pushes whether the object at 0x5827190 is there
 * and holds it; returns 1. */
// NONMATCHING: 87/91, 310 bytes as the base (round 604D: FUN_00c91140 defined, the Name's index
// kept; the result a statement of its own, so the copy is released before the push). Left: the
// array's object in rcx where the base has rdi (`mov rdi, [D_5827190]`, the loop's index then in edi)
int FUN_002a5950(lua_State *state) /* derived name */
{
    Name name;
    ArgumentReader00c8c290 reader(state);
    FUN_00c91140(&reader, &name);
    bool held = D_5827190 && D_5827190->has(name);
    pushBoolean(state, held);
    return 1;
}
