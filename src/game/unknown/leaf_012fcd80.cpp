/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns bit 0 of the byte at +0x1b (`movzx eax`, `and eax,
 * 1`, a 32-bit result). FUN_001ada10 calls it twice (0x1adb61, 0x1adb81) and
 * compares eax with 1, then sets a bit of its own record. Owner and meaning
 * unknown. */
struct Object012fcd80 { /* derived name */
    u8 unknown0[0x1b];
    u8 unknown1b;
};

u32 FUN_012fcd80(const Object012fcd80 *self) /* derived name */
{
    return self->unknown1b & 1;
}
