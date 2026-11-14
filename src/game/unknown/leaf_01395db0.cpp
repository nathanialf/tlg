/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 4 of the vtable at 0x16cf260 (its pointer at
 * 0x16cf290): 80 when the int at +0x68 is zero, else 80 times one more than the
 * count at +0xd8, at least two. Class and method unknown. */
struct Object01395db0 { /* derived name */
    u8 unknown0[0x68];
    int unknown68;
    u8 unknown6c[0x6c];
    u32 unknownd8;
};

u32 FUN_01395db0(const Object01395db0 *self) /* derived name */
{
    if (self->unknown68 == 0) {
        return 80;
    }
    u32 count = self->unknownd8 + 1;
    return (count > 2 ? count : 2) * 80;
}
