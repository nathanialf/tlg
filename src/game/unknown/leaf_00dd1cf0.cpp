/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"
#include "tlg_hks.h"

/* derived names: slot 19 of the vtables at 0x16bba90, 0x16bc170 and
 * 0x16d2818: each value of the range from its first to its last, the last
 * read again at each step, handed to slots 59 and 98, its mark (slot 20)
 * and slot 137 */
void Object013c8500::visitValues(const ValueRange00dd1cf0 *range)
{
    for (const HksObject *value = range->first; value != range->last; ++value) {
        beforeValue(value);
        enterValue(value);
        markValue(value);
        afterValue(value);
    }
}

/* derived names: slot 26: each 24-byte entry of the range below its last,
 * the last read again at each step, handed to slots 66 and 105, its mark
 * (slot 27) and slot 144 */
void Object013c8500::visitEntries(const EntryRange00dd1e90 *range)
{
    for (const Entry00dd1e90 *entry = range->first; entry < range->last; ++entry) {
        beforeEntry(entry);
        enterEntry(entry);
        markEntry(entry);
        afterEntry(entry);
    }
}
