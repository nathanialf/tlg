/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00c83870): calls
 * FUN_00db6b20 with the object, its 64-bit position at +0x50 and 0 while the
 * position is below the end at +0x48, and returns 0. The types are not traced. */
struct Object00c871e0 { /* derived name */
    u8 unknown0[0x48];
    u64 unknown48;
    u64 unknown50;
};

void FUN_00db6b20(Object00c871e0 *self, u64 position, int); /* derived name */

int FUN_00c871e0(Object00c871e0 *self) /* derived name */
{
    if (self->unknown50 < self->unknown48) {
        FUN_00db6b20(self, self->unknown50, 0);
    }
    return 0;
}
