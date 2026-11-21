/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_hks.h"

/* derived names: the object at 0x57c9390 as the queue's status sees it: its
 * bits at +0x188 */
struct Object057c9390 { /* derived name */
    u8 unknown0[0x188];
    u32 queueStatus; /* +0x188 (derived name): bit 0 "restart", bit 1 "ingame" */
};

extern Object057c9390 *D_57c9390;

/* derived names: the script C function "TricoGame_QueueStatus"
 * (FUN_001bd010, lea at 0x1db29a): with at least one argument, the bit its
 * string names ("restart" bit 0, "ingame" bit 1) of the status at +0x188 of
 * the object at 0x57c9390 set, or cleared when a second argument is false;
 * any other string changes nothing. The status is read before the names
 * are compared. Returns no results. The C function's own name is unknown. */
// NONMATCHING: the second argument's truth, as FUN_00a46970's and FUN_0046b050's: the base keeps
// the slot a select of null past the top (`cmovae rax, rcx; jae`) and reads the tag through it,
// the build folds the select into the branch; then r12 and r15 exchanged (the state, the flag)
int FUN_001b10f0(lua_State *state) /* derived name */
{
    int count = argumentCount(state);
    if (count > 0) {
        const HksObject *value = state->base;
        const char *name = value < state->top ? FUN_00db6b20(state, value, 0) : 0;
        int set = 1;
        if (count >= 2)
            set = toBoolean(state, 2);
        Object057c9390 *game = D_57c9390;
        u32 status = game->queueStatus;
        if (strcmp(name, "restart") == 0)
            status = set ? status | 1 : status & ~1u;
        else if (strcmp(name, "ingame") == 0)
            status = set ? status | 2 : status & ~2u;
        else
            return 0;
        game->queueStatus = status;
    }
    return 0;
}
