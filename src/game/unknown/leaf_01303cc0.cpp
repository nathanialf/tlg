/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the 0x400 bytes at +0x1d18 with memset, as a tail
 * call; slot 20 of the vtable at 0x16c3808 (its pointer at 0x16c38b8), the
 * vtable stored by FUN_012ffc30 FUN_013001f0 FUN_013002e0. Class and method
 * unknown. */
#include "tlg_libc.h"

struct Object01303cc0 { /* derived name */
    u8 unknown0[0x1d18];
    u8 unknown1d18[0x400];
};

void FUN_01303cc0(Object01303cc0 *self) /* derived name */
{
    memset(self->unknown1d18, 0, sizeof(self->unknown1d18));
}
