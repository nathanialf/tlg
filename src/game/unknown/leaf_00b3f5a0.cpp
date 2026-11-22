/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b5ae8.h"

/* derived names: slot 13 of the vtable at 0x16b5ae8 (its pointer at
 * 0x16b5b60) and, through the thunk 0xb3f650 (`add rdi, -0x58; jmp`), slot 0
 * of the base at +0x58: when the table has its entries, makes a vertex of
 * the entry each index of the record's chosen list names, one vertex per
 * index: the entry's point with w 0 and seven of its words, the short at
 * +0x0 widened (as FUN_01398150 does for the class at 0x16cf9f8). */
// NONMATCHING: greedy's assignment, as FUN_01398150's: the variant at +0x10 is loaded into
// r8d where the base reuses ecx (the record's register, dead after the movsxd); the thunk
// 0xb3f650 is equal but waits for its target's row.
void Object016b5ae8::FUN_00b3f5a0(Output016b5ae8 *output, int, int record)
{
    Entry016b5ae8 *entries = table->entries;
    if (!entries)
        return;
    const Array05943280<unsigned> &list = records->records.at(record).lists[records->variant];
    unsigned count = list.size();
    if (!count)
        return;
    Vertex016b5ae8 *vertices = output->vertices;
    const unsigned *indices = list.begin();
    for (unsigned i = 0; i < count; ++i) {
        const Entry016b5ae8 &entry = entries[indices[i]];
        Vertex016b5ae8 &vertex = vertices[i];
        vertex.unknown1c = entry.unknown0;
        vertex.unknown10 = entry.unknown4;
        vertex.unknown14 = entry.unknown8;
        vertex.unknown24 = entry.unknown10;
        vertex.unknown18 = entry.unknown14;
        vertex.unknown20 = entry.unknown24;
        vertex.unknown28 = entry.unknown28;
        vertex.position = Float4(entry.position.x, entry.position.y, entry.position.z, 0.0f);
    }
}
