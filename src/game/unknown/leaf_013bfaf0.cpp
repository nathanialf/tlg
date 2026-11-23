/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of a table (kind 5 of a value; FUN_00dd1d60, FUN_00dd0f90, FUN_00dd1380 and eight more call it by address): slot 45, then, when
 * the pointer is set and the object is walked for the first time, slots
 * 84, 6 (its mark, 0xdd0f90) and 123 */
void Object013c8500::visit(const Table00dd0f90 *table)
{
    beforeTable00dd0f90(table);
    if (table && firstVisit(table)) {
        enterTable00dd0f90(table);
        visit00dd0f90(table);
        afterTable00dd0f90(table);
    }
}
