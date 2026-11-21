/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cf9f8.h"

/* derived names: slot 9 of the vtable at 0x16cf9f8 (its pointer at
 * 0x16cfa58): when the table has its entries, copies each entry that an
 * index of a record's chosen list names from the table's source entries,
 * for every record. */
void Object016cf9f8::FUN_01399a00()
{
    Entry016cf9f8 *entries = table->entries;
    if (!entries)
        return;
    unsigned count = records->records.size();
    if (!count)
        return;
    const Entry016cf9f8 *source = table->source;
    for (unsigned i = 0; i < count; ++i) {
        const Array05943280<unsigned> &list = records->records.at(i).lists[records->variant];
        const unsigned *indices = list.begin();
        for (unsigned n = list.size(); n; --n) {
            const unsigned index = *indices++;
            entries[index].unknown0 = source[index].unknown0;
            entries[index].unknown4 = source[index].unknown4;
            entries[index].unknown8 = source[index].unknown8;
            entries[index].unknownc = source[index].unknownc;
            entries[index].unknown10 = source[index].unknown10;
            entries[index].unknown14 = source[index].unknown14;
            entries[index].unknown18 = source[index].unknown18;
        }
    }
}
