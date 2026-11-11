/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16af4d0 (+0x20 from the vtable stored at
 * 0x16af4b0): takes a copy of the handle its argument refers to and lets it
 * go, the reference count at +0x10 of the 32-byte entry of the table at
 * 0x17ac870 the handle's index selects raised (as leaf_013c9e00.cpp's handle
 * copy does) and lowered again, the entry passed to FUN_00d66e30 by its index
 * when the count drops to zero. The object itself is not read; its class is
 * not traced. */
struct Entry017ac870 { /* derived name */
    u8 unknown0[0x10];
    int unknown10; /* +0x10: the references */
    u8 unknown14[0xc];
};

extern Entry017ac870 D_17ac870[];

void FUN_00d66e30(unsigned index); /* derived name */

struct Handle008aefb0 /* derived name */
{
    unsigned index; /* derived name */

    Handle008aefb0(const Handle008aefb0 &other)
    {
        __sync_fetch_and_add(&D_17ac870[other.index].unknown10, 1);
        index = other.index;
    }

    ~Handle008aefb0()
    {
        if (index != 0 && __sync_fetch_and_add(&D_17ac870[index].unknown10, -1) == 1) {
            FUN_00d66e30(index);
        }
    }
};

struct Object008aefb0; /* derived name */

void FUN_008aefb0(Object008aefb0 *, const Handle008aefb0 &handle) /* derived name */
{
    Handle008aefb0 copy(handle);
}
