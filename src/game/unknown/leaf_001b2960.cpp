/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: a script C function: with at least one argument, stores
 * the first one's truth (nil and a false boolean false, anything else true;
 * false when the frame is empty) as an int at +0x288 of the object the
 * pointer at +0x48 of the object at 0x5938c40 holds, and returns 0 (no
 * results). The read of the type follows FUN_00a44f20's. The C function's own
 * name and its registration are not traced. */
struct Member05938c40_48 { /* derived name */
    u8 unknown0[0x288];
    int unknown288; /* +0x288: the flag */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x48];
    Member05938c40_48 *unknown48; /* +0x48 */
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: greedy's assignment as FUN_00a44f20's: the frame's top, base and
// count are in rsi, rcx and rax in the base, rcx, rax and rdx here, the flag's
// true set before the boolean test there; the order of the reads is the base's.
int FUN_001b2960(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        Member05938c40_48 *member = D_5938c40->unknown48;
        const HksObject *value = state->base < state->top ? state->base : 0;
        int type = state->base < state->top ? value->type & 0xf : 0;
        bool flag = false;
        if (type != 0) {
            flag = true;
            if (type == 1)
                flag = value->value.boolean != 0;
        }
        member->unknown288 = flag;
    }
    return 0;
}
