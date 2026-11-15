/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 110 of the vtable at 0x16c5590: stores the pointer at
 * +0xe488 of the object as two words of the record's word array at +0x18, at
 * the position the byte at +2 of the index's 4-byte entry gives, less 16.
 * Class and method unknown. */
struct Entry0132c680 { /* derived name */
    u8 unknown0[2];
    u8 unknown2;
    u8 unknown3;
};

struct Record0132c680 { /* derived name */
    const Entry0132c680 *unknown0;
    u8 unknown8[0x10];
    u32 *unknown18;
};

struct Object0132c680 { /* derived name */
    u8 unknown0[0xe488];
    void *unknowne488;
};

void FUN_0132c680(Object0132c680 *self, u32 index, Record0132c680 *record) /* derived name */
{
    const Entry0132c680 *entry = &record->unknown0[index];
    u32 *words = record->unknown18;
    void *value = self->unknowne488;
    u32 position = entry->unknown2 - 16u;
    *reinterpret_cast<void **>(&words[position]) = value;
}
