/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the int at +0x4c of its argument to 1 when bit 0 of the
 * byte at +0x48 of it is set (testb $1: a one-bit field, as a bool member
 * compiles to cmpb $0); the object itself is unused; slot 16 of the vtable at
 * 0x16b53f8 (its pointer at 0x16b5488), the vtable stored by FUN_00b1f8c0
 * FUN_01392720 FUN_01392750. FUN_00b205d0 and FUN_00ca34b0 have the same body.
 * Class, argument and method unknown. */
struct Object00b205d0; /* derived name */

struct Argument00b205d0 { /* derived name: the argument of FUN_00b205d0 and FUN_00ca34b0 */
    u8 unknown0[0x48];
    u8 unknown48 : 1; /* bit 0 of the byte at +0x48; its other bits not traced */
    u8 unknown49[0x4c - 0x49];
    int unknown4c;
};

void FUN_00b205d0(Object00b205d0 *, Argument00b205d0 *argument) /* derived name */
{
    if (argument->unknown48)
        argument->unknown4c = 1;
}
