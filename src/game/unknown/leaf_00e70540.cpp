/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks_string.h"

/* derived names: the script C function "GetDataPath" (FUN_00e705b0's
 * registration through FUN_00dd6ba0, lea at 0xe708a6): pushes the string of
 * the name at +0x90 of the record at +0xe8 of the object the pointer at
 * 0x5938c40 holds, nil when the name has no string, and returns 1 (one
 * result), through pushString (tlg_hks_string.h). The types are not traced
 * beyond these fields. */
struct Record05938c40_e8 { /* derived name */
    u8 unknown0[0x90];
    Name unknown90; /* +0x90 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xe8];
    Record05938c40_e8 *unknownE8; /* +0xe8 */
};

extern Object05938c40 *D_5938c40;

int FUN_00e70540(lua_State *state) /* derived name */
{
    pushString(state, D_17ac870[D_5938c40->unknownE8->unknown90.index].string0);
    return 1;
}
