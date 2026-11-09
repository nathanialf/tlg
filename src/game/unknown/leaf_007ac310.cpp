/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the int at +0x30 is set, adds its float argument to the
 * float at +0x28 and calls FUN_007a86a0 with the object as a tail call; slot 6
 * of the vtable at 0x16ade08 (its pointer at 0x16ade48). FUN_007a86a0 is
 * reached the same way from FUN_007aa080 and FUN_007ac310. Class and method
 * unknown. */
struct Object007ac310 { /* derived name */
    u8 unknown0[0x28];
    float unknown28;
    u8 unknown2c[4];
    int unknown30;
};

void FUN_007a86a0(Object007ac310 *self); /* derived name */

void FUN_007ac310(Object007ac310 *self, float value) /* derived name */
{
    if (self->unknown30) {
        self->unknown28 += value;
        FUN_007a86a0(self);
    }
}
