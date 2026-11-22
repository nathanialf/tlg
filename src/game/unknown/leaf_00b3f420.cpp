/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b5ae8.h"

/* derived names: slot 9 of the vtable at 0x16b5ae8 (its pointer at
 * 0x16b5b40) and, through the thunk 0xb3f4e0 (this - 0x50, the body inlined
 * into it), slot 0 of the base at +0x50: when the table has its entries,
 * copies each entry that an index of a record's chosen list names from the
 * table's source entries, for every record (as FUN_01399a00 does for the
 * class at 0x16cf9f8). */
void Object016b5ae8::FUN_00b3f420()
{
    Entry016b5ae8 *entries = table->entries;
    if (!entries)
        return;
    unsigned count = records->records.size();
    if (!count)
        return;
    const Entry016b5ae8 *source = table->source;
    for (unsigned i = 0; i < count; ++i) {
        const Array05943280<unsigned> &list = records->records.at(i).lists[records->variant];
        const unsigned *indices = list.begin();
        for (unsigned n = list.size(); n; --n) {
            const unsigned index = *indices++;
            entries[index] = source[index];
        }
    }
}
