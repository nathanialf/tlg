/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_game_name.h"

/* derived names: the object at +0x38 of the record at +0x108 of the object
 * the pointer at 0x57c9390 holds: its table of values by id (leaf_00a18070.cpp) */
struct Object00a18070;

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Object00a18070 *unknown38; /* +0x38 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

void FUN_00a17f20(Object00a18070 *self, const Name &value, const Name &id); /* derived name */

/* the script C function "SetBreakableStatus" (registered through
 * FUN_00c87e30, lea at 0x1db782): with exactly two arguments, the Names
 * their strings make are handed to FUN_00a17f20 with the table at +0x38 of
 * the record at +0x108 of the object the pointer at 0x57c9390 holds, the
 * first as the value and the second as the id; returns 0 (no results).
 * FUN_001b3e80 ("SetBreakableState") is the same body. The C function's own name is unknown. */
// NONMATCHING: 34/88: the base keeps both Names' indexes in registers across FUN_00a17f20
// (r14, ebx; the destructors test them without a reload): the callee's two Name arguments
// read only, which the link infers once FUN_00a174c0 (0xa174c0, not written), to which
// FUN_00a17f20 hands them, is in the module; the build reloads them from the stack.
int FUN_001b41c0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 2) {
        HashedString string;
        FUN_00e81bd0(&string, state, 1);
        Name value(string);
        FUN_00e81bd0(&string, state, 2);
        Name id(string);
        FUN_00a17f20(D_57c9390->unknown108->unknown38, value, id);
    }
    return 0;
}
