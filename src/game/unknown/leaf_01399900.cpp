/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cf9f8.h"
#include "tlg_libc.h"

/* derived names: slot 16 of the vtable at 0x16cfd08 (its pointer at
 * 0x16cfd98; FUN_01398620's class): when the table has its entries, for
 * each index of the record's chosen list whose element of the records'
 * table does not have bit 2 of its word at +0x3c set, writes a vertex of
 * the next place of the output (the first at the float the word at +0x64
 * gives, one every the word at +0x68 floats): its first four floats
 * cleared, then the entry's words at +0xc and +0x10 into the first two, the
 * ones at +0x1c and +0x20 into the fifth and sixth, and zero into the
 * seventh. The records are tlg_game_object016cf9f8.h's; the class is not
 * traced beyond these fields. */
struct Entry01399900 { /* derived name */
    u8 unknown0[0xc];
    float unknownc;
    float unknown10;
    u8 unknown14[8];
    float unknown1c;
    float unknown20;
    u8 unknown24[8];
};

struct Table01399900 { /* derived name */
    u8 unknown0[0x18];
    Entry01399900 *entries; /* +0x18 */
};

struct Position01399900 { /* derived name */
    float x;
    float y;
    float z;
    float w;
};

struct Vertex01399900 {        /* derived name */
    Position01399900 position; /* +0x0 */
    float u;                   /* +0x10 */
    float v;                   /* +0x14 */
    u32 unknown18;             /* +0x18 */
};

struct Object01399900 { /* derived name */
    u8 unknown0[0x20];
    Records016cf9f8 *records; /* +0x20 */
    u8 unknown28[0x8];
    Table01399900 *table; /* +0x30 */
    u8 unknown38[0x2c];
    u32 first;  /* +0x64: the first vertex's float */
    u32 stride; /* +0x68: the floats from one vertex to the next */
};

/* the third argument is not read */
// NONMATCHING: greedy's assignment, FUN_01398150's: the variant at +0x10 is loaded into r8d where
// the base reuses ecx (the record's register, dead after the movsxd); the rest equal.
void FUN_01399900(Object01399900 *self, float *output, int, int record) /* derived name */
{
    Entry01399900 *entries = self->table->entries;
    if (!entries)
        return;
    Records016cf9f8 *records = self->records;
    const Array05943280<unsigned> &list = records->records.at(record).lists[records->variant];
    unsigned count = list.size();
    if (!count)
        return;
    const Entry0137c090 *elements = records->table->entries;
    float *vertices = output + self->first;
    const unsigned *indices = list.begin();
    unsigned written = 0;
    for (unsigned i = 0; i < count; ++i) {
        const unsigned index = indices[i];
        if (elements[index].flags3c & 4)
            continue;
        Vertex01399900 &vertex =
            *reinterpret_cast<Vertex01399900 *>(vertices + written++ * self->stride);
        memset(&vertex.position, 0, sizeof(vertex.position));
        vertex.position.x = entries[index].unknownc;
        vertex.position.y = entries[index].unknown10;
        vertex.u = entries[index].unknown1c;
        vertex.v = entries[index].unknown20;
        vertex.unknown18 = 0;
    }
}
