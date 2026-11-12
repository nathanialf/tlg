/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Soldier_Debug_Explosion" (registered
 * through FUN_00c89b70 at 0x22365d): every soldier in the list at +0x900 of
 * the record at +0x38 of the object at 0x57c9390 (the pointers at +0x18,
 * their count at +0x20) whose state at +0x47c is 0 gets state 6; returns 0.
 * The state's values are not traced. */
struct Soldier00470400 /* derived name */
{
    u8 unknown0[0x47c];
    int state47c; /* +0x47c */
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x18];
    Soldier00470400 **soldiers18; /* +0x18 */
    int count20;                  /* +0x20 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

// The exit compare is the truncated induction variable (`inc rdx; cmp edx,
// ecx`): docs/DECISIONS.md D65.
int FUN_00470400(lua_State *) /* derived name */
{
    Member057c9390_38_900 *list = D_57c9390->unknown38->unknown900;
    const int count = list->count20;
    for (int i = 0; i < count; ++i) {
        Soldier00470400 *soldier = list->soldiers18[i];
        if (soldier && soldier->state47c == 0)
            soldier->state47c = 6;
    }
    return 0;
}
