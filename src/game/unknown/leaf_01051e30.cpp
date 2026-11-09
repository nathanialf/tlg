/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_0104c900 passes to FUN_010622f0 (lea at
 * 0x104f04f): when its int argument is zero, calls FUN_01053020 with the
 * pointer at +0x2a0, as a tail call. The types and the return type are not
 * traced. Class and method unknown. */
struct Target01051e30; /* derived name */

struct Object01051e30 { /* derived name */
    u8 unknown0[0x2a0];
    Target01051e30 *unknown2a0;
};

void FUN_01053020(Target01051e30 *target); /* derived name */

void FUN_01051e30(Object01051e30 *self, int flag) /* derived name */
{
    if (!flag) {
        FUN_01053020(self->unknown2a0);
    }
}
