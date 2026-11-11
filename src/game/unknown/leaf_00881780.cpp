/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "GameMenu_AutoAsing_SelectTitleContinue"
 * (registered through FUN_00c87e30 at 0x8818ef): clears the ints at +0xe0 and
 * +0x210 and sets the one at +0x218 to 1 in the record the pointer at +0xd0
 * of the object at 0x57c9390 holds (the pointer read again after each store),
 * and returns 0 (no results). The record's type is not traced. */
struct Member057c9390_d0 { /* derived name */
    u8 unknown0[0xe0];
    int unknowne0; /* +0xe0 */
    u8 unknowne4[0x12c];
    int unknown210; /* +0x210 */
    u8 unknown214[4];
    int unknown218; /* +0x218 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0xd0];
    Member057c9390_d0 *unknownd0; /* +0xd0 */
};

extern Object057c9390 *D_57c9390;

int FUN_00881780(lua_State *) /* derived name */
{
    D_57c9390->unknownd0->unknowne0 = 0;
    D_57c9390->unknownd0->unknown210 = 0;
    D_57c9390->unknownd0->unknown218 = 1;
    return 0;
}
