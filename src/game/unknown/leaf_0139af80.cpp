/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cf9f8.h"

/* derived names: slot 15 of the vtable at 0x16cfb98 (its pointer at
 * 0x16cfc20): FUN_01398150's copy over a table of 68-byte entries: when the
 * table has its entries, for each index of the record's chosen list copies
 * words of the entry it names into the output's vertex of that place: the
 * eight from +0xc, then the ten from +0x1c, whose first four go where the
 * first copy put them (written twice: the entry's words are read again
 * between, as the vertices may alias them). The records are tlg_game_object016cf9f8.h's; the class is
 * not traced beyond the two pointers. */
struct Entry0139af80 { /* derived name */
    u8 unknown0[0xc];
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

struct Table0139af80 { /* derived name */
    u8 unknown0[0x18];
    Entry0139af80 *entries; /* +0x18 */
};

struct Vertex0139af80 { /* derived name */
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
    u8 unknown38[8];
};

struct Output0139af80 { /* derived name */
    u8 unknown0[0x28];
    Vertex0139af80 *vertices; /* +0x28 */
};

struct Object0139af80 { /* derived name */
    u8 unknown0[0x20];
    Records016cf9f8 *records; /* +0x20 */
    u8 unknown28[0x8];
    Table0139af80 *table; /* +0x30 */
};

/* the vertex's first eight words from the entry's words at +0xc to +0x28
 * (FUN_01398150's four, then four more) */
inline void copyFirst(Vertex0139af80 &vertex, const Entry0139af80 &entry) /* derived name */
{
    vertex.unknown0 = entry.unknownc;
    vertex.unknown4 = entry.unknown10;
    vertex.unknown10 = entry.unknown14;
    vertex.unknown14 = entry.unknown18;
    vertex.unknown8 = entry.unknown1c;
    vertex.unknownc = entry.unknown20;
    vertex.unknown18 = entry.unknown24;
    vertex.unknown1c = entry.unknown28;
}

/* the vertex's words from the entry's ten at +0x1c to +0x40, the first four
 * as copyFirst puts them */
inline void copySecond(Vertex0139af80 &vertex, const Entry0139af80 &entry) /* derived name */
{
    vertex.unknown8 = entry.unknown1c;
    vertex.unknownc = entry.unknown20;
    vertex.unknown18 = entry.unknown24;
    vertex.unknown1c = entry.unknown28;
    vertex.unknown20 = entry.unknown2c;
    vertex.unknown24 = entry.unknown30;
    vertex.unknown28 = entry.unknown34;
    vertex.unknown2c = entry.unknown38;
    vertex.unknown30 = entry.unknown3c;
    vertex.unknown34 = entry.unknown40;
}

/* the third argument is not read */
void FUN_0139af80(Object0139af80 *self, Output0139af80 *output, int, int record) /* derived name */
{
    Entry0139af80 *entries = self->table->entries;
    if (!entries)
        return;
    const Array05943280<unsigned> &list =
        self->records->records.at(record).list(self->records->variant);
    unsigned count = list.size();
    if (!count)
        return;
    Vertex0139af80 *vertices = output->vertices;
    const unsigned *indices = list.begin();
    for (unsigned i = 0; i < count; ++i) {
        const Entry0139af80 &entry = entries[indices[i]];
        Vertex0139af80 &vertex = vertices[i];
        copyFirst(vertex, entry);
        copySecond(vertex, entry);
    }
}
