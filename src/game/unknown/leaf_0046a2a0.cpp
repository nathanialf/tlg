/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: the script C function "Soldier_NotifyFromCondor"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x223068): reads
 * its first argument as a name (nameArgument) and, when it names
 * "DeclarationBattle" (the static name at 0x57d57e0, func_00470450.cpp),
 * sets the float at +0x134 of the record at +0x900 of the global's member
 * at +0x38 to its float at +0x44 plus a half; returns 0 (no results). */
struct Record057c9390_38_900 /* derived name */
{
    u8 unknown0[0x44];
    float unknown44; /* +0x44 */
    u8 unknown48[0xec];
    float unknown134; /* +0x134 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Record057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;
extern Name D_57d57e0; /* "DeclarationBattle" */

int FUN_0046a2a0(lua_State *state) /* derived name */
{
    const Name notice = nameArgument(state, 1);
    if (notice == D_57d57e0) {
        Record057c9390_38_900 *record = D_57c9390->unknown38->unknown900;
        record->unknown134 = record->unknown44 + 0.5f;
    }
    return 0;
}
