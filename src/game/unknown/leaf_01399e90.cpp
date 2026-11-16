/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cf9f8.h"

/* derived names: slot 15 of the vtable at 0x16cf9f8 (its pointer at
 * 0x16cfa80) and, through the thunk 0x1398150 (this - 0x58, the body
 * inlined into it), slot 0 of the base at +0x58: when the table has its
 * entries, copies four floats of the entry each index of the record's
 * chosen list names into the output's vertices, one vertex per index. */
// NONMATCHING: greedy's assignment: the variant at +0x10 is loaded into r8d where the base
// reuses ecx (the record's register, dead after the movsxd); the same in the thunk 0x1398150.
void Object016cf9f8::FUN_01398150(Output016cf9f8 *output, int, int record)
{
    Entry016cf9f8 *entries = table->entries;
    if (!entries)
        return;
    const Array05943280<unsigned> &list = records->records[record].lists[records->variant];
    unsigned count = list.size();
    if (!count)
        return;
    Vertex016cf9f8 *vertices = output->vertices;
    const unsigned *indices = list.begin();
    for (unsigned i = 0; i < count; ++i) {
        const Entry016cf9f8 &entry = entries[indices[i]];
        Vertex016cf9f8 &vertex = vertices[i];
        vertex.unknown0 = entry.unknownc;
        vertex.unknown4 = entry.unknown10;
        vertex.unknown10 = entry.unknown14;
        vertex.unknown14 = entry.unknown18;
    }
}
