/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtable at 0x16b7a40 (its address also taken by
 * FUN_00c0fb30): the address of the entry the index at +0xe0 selects in the
 * block the record at +0xd8 holds at +0x28: the block's data (at the offset
 * its word at +0x14 gives) plus the index's word in its offset table (at the
 * offset its word at +0x10 gives); null without the record. Class and method
 * unknown. */
struct Block00be5650 { /* derived name */
    u8 unknown0[0x10];
    u32 offsetsOffset; /* derived name */
    u32 dataOffset;    /* derived name */
};

struct Record00be5650 { /* derived name */
    u8 unknown0[0x28];
    const Block00be5650 *block;
};

struct Object00be5650 { /* derived name */
    u8 unknown0[0xd8];
    const Record00be5650 *unknownd8;
    u32 index;
};

// NONMATCHING: list-ilp order of the two block additions (the base adds the offset table's offset
// first, rcx, then the data's, rdx; the compile the reverse); 3.8.1 gives the base's order, 3.9.1 and
// 4.0.0 this one (round 135B, prebuilt releases), as FUN_013c8720
const u8 *FUN_00be5650(const Object00be5650 *self) /* derived name */
{
    const Record00be5650 *record = self->unknownd8;
    if (!record) {
        return 0;
    }
    const u8 *block = reinterpret_cast<const u8 *>(record->block);
    const u8 *data = block + record->block->dataOffset;
    const u32 *offsets = reinterpret_cast<const u32 *>(block + record->block->offsetsOffset);
    return data + offsets[self->index];
}
