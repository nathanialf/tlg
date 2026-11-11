/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16b7a40 (its pointer at
 * 0x16b7a80): 0 without the record at +0xd8, else the u32 the index at +0xe0
 * selects in the array that starts the u32 at +0xc of the block at +0x28 of
 * the record past that block's start. Class and method unknown. */
struct Block00be5680 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc;
};

struct Record00be5680 { /* derived name */
    u8 unknown0[0x28];
    Block00be5680 *unknown28;
};

struct Object00be5680 { /* derived name */
    u8 unknown0[0xd8];
    Record00be5680 *unknownd8;
    u32 unknowne0;
};

u32 FUN_00be5680(const Object00be5680 *self) /* derived name */
{
    const Record00be5680 *record = self->unknownd8;
    if (!record) {
        return 0;
    }
    const Block00be5680 *block = record->unknown28;
    const u32 *values =
        reinterpret_cast<const u32 *>(reinterpret_cast<const u8 *>(block) + block->unknownc);
    return values[self->unknowne0];
}
