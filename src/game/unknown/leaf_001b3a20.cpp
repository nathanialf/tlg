/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the script C function "PlayGoOpenDialog" (FUN_001bd010, lea
 * at 0x1db6f2): with at least one argument, takes the number FUN_00db6f40
 * reads from the first, truncated to an int (0 when the frame is empty), as
 * an index; when the byte at +0x14 plus that index of the record at +0xf58 of
 * the object the pointer at 0x5938c40 holds is 0 and the record's int at +0xc
 * (FUN_001b3a80's open flag) is 0, sets that flag to 1 and stores the index
 * at +0x10. Returns 0 (no results). */
struct Member05938c40_f58 { /* derived name */
    u8 unknown0[0xc];
    int unknownc;
    int unknown10;
    u8 unknown14[1]; /* indexed by the argument; its length is not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf58];
    Member05938c40_f58 *unknownf58;
};

extern Object05938c40 *D_5938c40;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */

int FUN_001b3a20(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int index = 0;
        if (state->base < state->top)
            index = FUN_00db6f40(state, state->base);
        Member05938c40_f58 *record = D_5938c40->unknownf58;
        if (!record->unknown14[index] && !record->unknownc) {
            record->unknownc = 1;
            record->unknown10 = index;
        }
    }
    return 0;
}
