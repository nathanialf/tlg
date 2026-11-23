/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of a user data (kind 7 of a value; FUN_00dd1d60,
 * FUN_00dd1380 and FUN_00dd2180 call it by address): slot 47, then, when
 * the pointer is set and the user data is walked for the first time, slots
 * 86, 7 (its mark, FUN_00dd1380 in the vtables at 0x16bba90 and 0x16bc170)
 * and 125 */
void Object013c8500::visit(const UserData00dd2cf0 *userData)
{
    beforeUserData(userData);
    if (userData && firstVisit(userData)) {
        enterUserData(userData);
        markUserData(userData);
        afterUserData(userData);
    }
}
