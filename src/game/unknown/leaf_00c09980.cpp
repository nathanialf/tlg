/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_table0135b360.h"

extern const Name D_58b7284; /* derived name */
extern const Name D_58b7288; /* derived name */
extern const Name D_58b728c; /* derived name */
extern const Name D_58b7290; /* derived name */

/* FUN_00c09980: the names and slots made empty, the words at +0x10 cleared
 * after the slots (one 16-byte store), the four names set from the names at
 * 0x58b7284 to 0x58b7290 and no slot used */
Table0135b360::Table0135b360()
{
    unknown10 = 0;
    unknown14 = 0;
    unknown18 = 0;
    unknown1c = 0;
    name0 = D_58b7284;
    name4 = D_58b7288;
    name8 = D_58b728c;
    namec = D_58b7290;
    count = 0;
}
