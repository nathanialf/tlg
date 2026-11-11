/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether this object is the owner of the block its second
 * argument points to, as an int: the owner the table at 0x5943280 gives for
 * the index in the 16-byte header before the block when the header's tag is
 * 0xa, else null (compared too: the `jne` lands on the compare with rcx 0); a
 * null block is read at 0 (`cmove`). Slot 7 of the vtable at 0x16b8c00 (its
 * pointer at 0x16b8c48), the vtable of Object00ca24c0 (leaf_00ca24c0.cpp). The
 * owner's class is not traced. */
/* The 16-byte header before a block the table at 0x5943280 types: a tag byte,
 * then at +0x2 the index of the block's owner in that table. derived names. */
struct BlockHeader05943280 { /* derived name */
    u8 tag;
    u8 unknown1;
    u16 owner;
    u8 unknown4[0xc];
};

class Owner05943280; /* derived name */

extern Owner05943280 *D_5943280[];

class Object00ca24c0; /* derived name */

int FUN_00ca2510(const Object00ca24c0 *self, const void *block) /* derived name */
{
    const BlockHeader05943280 *header =
        block ? static_cast<const BlockHeader05943280 *>(block) - 1 : 0;
    const Owner05943280 *owner = header->tag == 0xa ? D_5943280[header->owner] : 0;
    return reinterpret_cast<const Owner05943280 *>(self) == owner;
}
