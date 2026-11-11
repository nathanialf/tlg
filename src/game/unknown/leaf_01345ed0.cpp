/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtable at 0x16c70f8 (its pointer at
 * 0x16c7138): clears bit 0 of the u16 at +0x16 of each object in its
 * argument's array of pointers (+0x58, the count a u32 at +0x60). The object
 * (this) is not read. Class and method unknown. */
struct Item01345ed0 { /* derived name */
    u8 unknown0[0x16];
    u16 unknown16;
};

struct Argument01345ed0 { /* derived name */
    u8 unknown0[0x58];
    Item01345ed0 **unknown58;
    u32 unknown60;
};

void FUN_01345ed0(void *, Argument01345ed0 *argument) /* derived name */
{
    Item01345ed0 **item = argument->unknown58;
    Item01345ed0 **end = item + argument->unknown60;
    for (; item != end; ++item) {
        (*item)->unknown16 &= ~1;
    }
}
