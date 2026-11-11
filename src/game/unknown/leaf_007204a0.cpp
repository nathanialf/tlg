/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the vtable at 0x16ac7c8: FUN_01367fa0 on the
 * pointers at +0xb50 and +0xb40, in that order; returns 1. Class and method
 * unknown. */
struct Target007204a0; /* derived name */

struct Object007204a0 { /* derived name */
    u8 unknown0[0xb40];
    Target007204a0 *unknownb40;
    u8 unknownb48[8];
    Target007204a0 *unknownb50;
};

void FUN_01367fa0(Target007204a0 *target); /* derived name */

int FUN_007204a0(Object007204a0 *self) /* derived name */
{
    FUN_01367fa0(self->unknownb50);
    FUN_01367fa0(self->unknownb40);
    return 1;
}
