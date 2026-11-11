/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b37b8 (a vtable slot; its vtable without
 * a row): through the pointer at +0x8 to the record whose first field points
 * to the owner, when the owner's pointer at +0xd68 is set, stores 3 at +0x294
 * of what it points to if the owner's pointer at +0x390 is set and the byte at
 * +0x2d of its target nonzero, else 2; then clears the int at +0x18. Class
 * and method unknown; the types beyond their widths are not traced. */
struct Flags00ac7c40 { /* derived name */
    u8 unknown0[0x2d];
    u8 unknown2d; /* +0x2d */
};

struct Target00ac7c40 { /* derived name */
    u8 unknown0[0x294];
    int unknown294; /* +0x294 */
};

struct Owner00ac7c40 { /* derived name */
    u8 unknown0[0x390];
    Flags00ac7c40 *unknown390; /* +0x390 */
    u8 unknown398[0x9d0];
    Target00ac7c40 *unknownd68; /* +0xd68 */
};

struct Handle00ac7c40 {   /* derived name */
    Owner00ac7c40 *owner; /* +0x0 */
};

struct Object00ac7c40 {       /* derived name */
    u8 unknown0[8];           /* +0x0: the vtable pointer */
    Handle00ac7c40 *unknown8; /* +0x8 */
    u8 unknown10[8];
    int unknown18; /* +0x18 */
};

void FUN_00ac7c40(Object00ac7c40 *self) /* derived name */
{
    Owner00ac7c40 *owner = self->unknown8->owner;
    if (Target00ac7c40 *target = owner->unknownd68) {
        Flags00ac7c40 *flags = owner->unknown390;
        target->unknown294 = flags && flags->unknown2d != 0 ? 3 : 2;
    }
    self->unknown18 = 0;
}
