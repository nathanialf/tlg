/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a copy of the handle at 0xa4 of the object, by the
 * hidden result pointer: the handle's copy constructor (leaf_013c9e00.cpp's)
 * takes a reference, an atomic increment of the int at +0x10 of the 32-byte
 * entry of the table at 0x17ac870 its index selects, then copies the index
 * (reloaded after the increment). Slot 27 of the vtable at 0x16bdc60 (its
 * pointer at 0x16bdd48), stored by FUN_00e5c990 and FUN_00e5d180. The record's
 * other fields are not traced. */
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

struct Object013c9e20 { /* derived name */
    u8 unknown0[0xa4];
    Handle013c9e00 unknowna4;
};

Handle013c9e00 FUN_013c9e20(const Object013c9e20 *self) /* derived name */
{
    return self->unknowna4;
}
