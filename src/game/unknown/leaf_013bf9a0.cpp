/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of slot 14's record (kind 12 of a value; FUN_00dd1d60, FUN_00dd0f90, FUN_00dd11d0 and FUN_00dd1380 call it by address): slot 46, then, when
 * the pointer is set and the object is walked for the first time, slots
 * 85, 14 (its mark, 0xdd11d0) and 124 */
void Object013c8500::visit(const Record00dd11d0 *record)
{
    beforeRecord00dd11d0(record);
    if (record && firstVisit(record)) {
        enterRecord00dd11d0(record);
        visit00dd11d0(record);
        afterRecord00dd11d0(record);
    }
}
