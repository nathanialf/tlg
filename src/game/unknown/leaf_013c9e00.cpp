/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a copy of the handle its third argument refers to (by
 * the hidden result pointer: the handle has a copy constructor), the copy
 * taking a reference: an atomic increment (`lock inc`) of the int at +0x10 of
 * the 32-byte entry of the table at 0x17ac870 its index selects, then the
 * index copied (reloaded after the increment). Slot 28 of the vtable at
 * 0x16bdb40 (its pointer at 0x16bdc30), stored by FUN_00c4fdb0, FUN_00e5b7e0
 * and FUN_00e5b830; the object itself is not read. The table is the game's
 * object (leaf_01373a50.cpp). */
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

struct Object013c9e00; /* derived name */

Handle013c9e00 FUN_013c9e00(Object013c9e00 *, const Handle013c9e00 &handle) /* derived name */
{
    return handle;
}
