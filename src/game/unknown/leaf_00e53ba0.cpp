/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_types.h"

/* derived names: where one value of an object's block of values lies: its
 * byte offset into the block (+0x4), and in the flag word whether it is an
 * array (bit 9) and, in its third byte, how many four-byte entries the array
 * holds (the base tests bit 9 of the 32-bit word, then reads the count back
 * as the byte at +0x2). The other bits are not traced. */
struct ValueSlot00e53ba0 { /* derived name */

    union {
        u32 flags; /* +0x0: bit 9, an array */

        struct {
            u8 unknown0[2];
            u8 count; /* +0x2 */
            u8 unknown3;
        };
    };

    u32 offset; /* +0x4 */
};

/* derived names: the owner of the block: its size at +0x838, the block
 * from +0x83c. The other fields are not traced. */
struct Object00e53ba0 { /* derived name */
    u8 unknown0[0x838];
    u32 blockSize; /* +0x838 */
    u8 block[1];   /* +0x83c */

    /* the name at a byte offset into the block */
    Name *nameAt(size_t offset) /* derived name */
    {
        return reinterpret_cast<Name *>(block + offset);
    }
};

/* derived name: releases the name, or each name of the array, that the slot
 * places in the owner's block; a slot past the block's end is left alone.
 * FUN_00e10280 calls it three times. */
// NONMATCHING: the entry: the base reads the flag word once (`mov eax, [r15]; test ah, 2`) and
// takes the array's count from it (`shr eax, 0x10; test al, al`), the build tests the byte at +0x1
// and loads the count's byte at +0x2 (MemoryDependence finds no load of the same address to
// forward from); the loop is equal
void FUN_00e53ba0(Object00e53ba0 *owner, const ValueSlot00e53ba0 *slot)
{
    if (slot->offset >= owner->blockSize)
        return;
    if (!(slot->flags & 0x200)) {
        owner->nameAt(slot->offset)->release();
        return;
    }
    for (u32 i = 0; i < slot->count; ++i)
        owner->nameAt(slot->offset + i * sizeof(Name))->release();
}
