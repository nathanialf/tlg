/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method that calls FUN_0083d2d0 with the object and
 * the pointer at +0x28 as a tail call; slot 7 of the vtable at 0x16aecc8 (its
 * pointer at 0x16aed10), the vtable stored by FUN_0083cf60 FUN_01370850. The
 * pointer's target and the return type are not traced. Class and method
 * unknown. */
struct Target0083d5c0; /* derived name */

struct Object0083d5c0 { /* derived name */
    u8 unknown0[0x28];
    Target0083d5c0 *unknown28;
};

void FUN_0083d2d0(Object0083d5c0 *self, Target0083d5c0 *target); /* derived name */

void FUN_0083d5c0(Object0083d5c0 *self) /* derived name */
{
    FUN_0083d2d0(self, self->unknown28);
}
