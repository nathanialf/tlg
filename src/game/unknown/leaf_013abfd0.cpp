/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a copy of the handle at 0x1bc of its third argument
 * (the object itself is not read), by the hidden result pointer: the handle's
 * copy constructor (leaf_013c9e00.cpp's) takes a reference, an atomic
 * increment of the int at +0x10 of the 32-byte entry of the table at 0x17ac870
 * its index selects, then copies the index (reloaded after the increment).
 * Slot 9 of the vtable at 0x16b8db8 (its pointer at 0x16b8e10), stored by
 * FUN_00ca3e70. The record's other fields are not traced. */
struct Entry017ac870 { /* derived name */
    u8 unknown0[0x10];
    int unknown10; /* +0x10: the references */
    u8 unknown14[0xc];
};

extern Entry017ac870 D_17ac870[];

struct Handle013c9e00 /* derived name */
{
    unsigned index; /* derived name */

    Handle013c9e00(const Handle013c9e00 &other)
    {
        __sync_fetch_and_add(&D_17ac870[other.index].unknown10, 1);
        index = other.index;
    }
};

struct Argument013abfd0 { /* derived name */
    u8 unknown0[0x1bc];
    Handle013c9e00 unknown1bc;
};

Handle013c9e00 FUN_013abfd0(struct Object013abfd0 *,
                            const Argument013abfd0 *argument) /* derived name */
{
    return argument->unknown1bc;
}
