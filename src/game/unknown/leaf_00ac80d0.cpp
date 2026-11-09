/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of a soldier AI mode, slot 2 of the vtable at
 * 0x16b37d0 (its pointer at 0x16b37f0), the vtable stored by FUN_00abf490:
 * calls FUN_00abf840 on the pointer at +0x8 as a tail call. Slot 3 of the same
 * vtable returns the address of the mode's id object (round 110A). The
 * pointer's target and the return type are not traced. Class and method
 * unknown. */
struct Target00abf840; /* derived name */

struct Object00ac80d0 { /* derived name */
    u8 unknown0[0x8];
    Target00abf840 *unknown8;
};

void FUN_00abf840(Target00abf840 *target); /* derived name */

void FUN_00ac80d0(Object00ac80d0 *self) /* derived name */
{
    FUN_00abf840(self->unknown8);
}
