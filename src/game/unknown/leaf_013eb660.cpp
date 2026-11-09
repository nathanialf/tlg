/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_009f0260 with the object at +0x20 and its third and
 * fourth arguments (32-bit), as a tail call, its second unused; slot 8 of the
 * vtable at 0x16d4f90 (its pointer at 0x16d4fe0), the vtable stored by
 * FUN_00fe9df0 FUN_013ed3c0; slot 8 of the vtable at 0x16d7690 (its pointer at
 * 0x16d76e0), the vtable stored by FUN_012564c0 FUN_01483140. FUN_009f0260
 * keeps both as 32-bit values (movl esi, edx) and takes the count at +0x30 of
 * its object through FUN_01331c10. The types and the return type are not
 * traced. Class and method unknown. */
struct Target013eb660; /* derived name */

struct Object013eb660 { /* derived name */
    u8 unknown0[0x20];
    Target013eb660 *unknown20;
};

void FUN_009f0260(Target013eb660 *target, int a, int b); /* derived name */

void FUN_013eb660(Object013eb660 *self, void *, int a, int b) /* derived name */
{
    FUN_009f0260(self->unknown20, a, b);
}
