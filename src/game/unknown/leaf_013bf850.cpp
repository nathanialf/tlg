/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of a string (kind 4 of a value; FUN_00dd1d60, FUN_00dd1dc0, FUN_00dd2190 and five more call it by address): slot 44, then, when
 * the pointer is set and the object is walked for the first time, slots
 * 83, 5 (its mark, 0xdd0f80) and 122 */
void Object013c8500::visit(const String00dd2f70 *string)
{
    beforeString(string);
    if (string && firstVisit(string)) {
        enterString(string);
        markString(string);
        afterString(string);
    }
}
