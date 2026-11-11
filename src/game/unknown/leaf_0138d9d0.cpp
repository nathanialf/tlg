/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the first field of the 32-byte entry of the table at
 * 0x17ac870 that the 12-byte entry at an index of the array the pointer at
 * +0x18 holds (its count the int at +0x10) refers to, or the third argument
 * when the index is out of range or the entry's address null; slot 5 of the
 * vtable at 0x16ce490 (its pointer at 0x16ce4c8), stored by FUN_00a64740 (the
 * object at 0x5828630). The fields' types beyond their widths are not traced. */
struct Entry017ac870 { /* derived name */
    void *unknown0;
    u8 unknown8[0x18];
};

extern Entry017ac870 D_17ac870[];

struct Entry0138d9d0 { /* derived name */
    unsigned unknown0;
    u8 unknown4[8];
};

struct Object0138d9d0 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[4];
    Entry0138d9d0 *unknown18;
};

void *FUN_0138d9d0(const Object0138d9d0 *self, int index, void *value) /* derived name */
{
    const Entry0138d9d0 *entry =
        index >= 0 && index < self->unknown10 ? &self->unknown18[index] : 0;
    if (entry)
        return D_17ac870[entry->unknown0].unknown0;
    return value;
}
