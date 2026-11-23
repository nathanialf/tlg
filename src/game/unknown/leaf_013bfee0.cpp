/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of slot 16's record (FUN_00dd1950 and FUN_00dd1af0 call it by address): slot 55, then, when
 * the pointer is set and the object is walked for the first time, slots
 * 94, 16 (its mark, 0xdd1af0) and 133 */
void Object013c8500::visit(const Record00dd1af0 *record)
{
    beforeRecord00dd1af0(record);
    if (record && firstVisit(record)) {
        enterRecord00dd1af0(record);
        visit00dd1af0(record);
        afterRecord00dd1af0(record);
    }
}
