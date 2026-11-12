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

const u8 *FUN_00be5650(const Object00be5650 *self) /* derived name */
{
    const Record00be5650 *record = self->unknownd8;
    if (!record) {
        return 0;
    }
    /* the block's offsets are relative to its own address: each is added to
     * the address as an integer, offset first (0xbe5668: `add rcx, rax` on
     * the offset's register) */
    u64 block = reinterpret_cast<u64>(record->block);
    u64 data = record->block->dataOffset + block;
    const u32 *offsets = reinterpret_cast<const u32 *>(record->block->offsetsOffset + block);
    return reinterpret_cast<const u8 *>(data + offsets[self->index]);
}
