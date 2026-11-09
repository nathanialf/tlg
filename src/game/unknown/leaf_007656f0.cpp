/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method that calls FUN_007196a0 on the pointer at
 * +0x68 as a tail call; slot 7 of the vtable at 0x16aca58 (its pointer at
 * 0x16acaa0), no storing constructor listed (slots 0 and 1 FUN_00765660 and
 * FUN_007656d0). The pointer's target and the return type are not traced.
 * Class and method unknown. */
struct Target007196a0; /* derived name */

struct Object007656f0 { /* derived name */
    u8 unknown0[0x68];
    Target007196a0 *unknown68;
};

void FUN_007196a0(Target007196a0 *target); /* derived name */

void FUN_007656f0(Object007656f0 *self) /* derived name */
{
    FUN_007196a0(self->unknown68);
}
