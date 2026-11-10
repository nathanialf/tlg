/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether its 8-byte argument equals the 64-bit value
 * at +0x18, 0 when the given size is not 8; slot 12 of the vtable at 0x16d34d0
 * (its pointer at 0x16d3540). Class and method unknown. */
struct Object013cc850 { /* derived name */
    u8 unknown0[0x18];
    u64 unknown18;
};

int FUN_013cc850(const Object013cc850 *self, const u64 *value, int size) /* derived name */
{
    return size == 8 && *value == self->unknown18;
}
