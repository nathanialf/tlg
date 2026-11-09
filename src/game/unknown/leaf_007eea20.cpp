/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the two ints at +0x2e7c and +0x2e80 (one 8-byte store)
 * when both of its int arguments are zero, and returns 1; slot 6 of the vtable
 * at 0x16ae088 (its pointer at 0x16ae0c8). Class and method unknown. */
struct Object007eea20 { /* derived name */
    u8 unknown0[0x2e7c];
    int unknown2e7c;
    int unknown2e80;
};

int FUN_007eea20(Object007eea20 *self, int a, int b) /* derived name */
{
    if (a == 0 && b == 0) {
        self->unknown2e7c = 0;
        self->unknown2e80 = 0;
    }
    return 1;
}
