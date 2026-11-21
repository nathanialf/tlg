/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cf9f8.h"

/* derived names: slot 9 of the vtable at 0x16cfb98 (its pointer at
 * 0x16cfbf0): FUN_01399a00's copy over a table of 68-byte entries: when
 * the table has its entries, copies each entry that an index of a record's
 * chosen list names from the table's source entries, the seventeen words one
 * by one, for every record. The records are tlg_game_object016cf9f8.h's;
 * the class is not traced beyond the two pointers. */
struct Entry0139a0c0 { /* derived name */
    float unknown0;
    float unknown4;
    float unknown8;
    float unknownc;
    float unknown10;
    float unknown14;
    float unknown18;
    float unknown1c;
    float unknown20;
    float unknown24;
    float unknown28;
    float unknown2c;
    float unknown30;
    float unknown34;
    float unknown38;
    float unknown3c;
    float unknown40;
};

struct Table0139a0c0 { /* derived name */
    u8 unknown0[0x10];
    const Entry0139a0c0 *source; /* +0x10 */
    Entry0139a0c0 *entries;      /* +0x18 */
};

struct Object0139a0c0 { /* derived name */
    u8 unknown0[0x20];
    Records016cf9f8 *records; /* +0x20 */
    u8 unknown28[0x8];
    Table0139a0c0 *table; /* +0x30 */
};

void FUN_0139a0c0(Object0139a0c0 *self) /* derived name */
{
    Entry0139a0c0 *entries = self->table->entries;
    if (!entries)
        return;
    unsigned count = self->records->records.size();
    if (!count)
        return;
    const Entry0139a0c0 *source = self->table->source;
    for (unsigned i = 0; i < count; ++i) {
        const Array05943280<unsigned> &list =
            self->records->records.at(i).lists[self->records->variant];
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
            entries[index].unknown1c = source[index].unknown1c;
            entries[index].unknown20 = source[index].unknown20;
            entries[index].unknown24 = source[index].unknown24;
            entries[index].unknown28 = source[index].unknown28;
            entries[index].unknown2c = source[index].unknown2c;
            entries[index].unknown30 = source[index].unknown30;
            entries[index].unknown34 = source[index].unknown34;
            entries[index].unknown38 = source[index].unknown38;
            entries[index].unknown3c = source[index].unknown3c;
            entries[index].unknown40 = source[index].unknown40;
        }
    }
}
