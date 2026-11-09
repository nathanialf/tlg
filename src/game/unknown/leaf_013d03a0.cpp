/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x24 is above 1, as an int (setg,
 * then movzx to eax; FUN_00f7d610 calls it directly at 0xf7ddfb and tests eax);
 * slot 3 of the vtables at 0x16d39a8 (stored by FUN_00f4de30), 0x16d3d00
 * (stored by FUN_00f7c020 FUN_00f7d610) and 0x16d69c8 (stored by
 * FUN_01210dc0). Slot 2 (FUN_013d03b0) increments that int on one outcome and
 * sets it to 2 on another: a state or attempt count, signed by the compare.
 * Class and method unknown. */
struct Object013d03a0 { /* derived name */
    u8 unknown0[0x24];
    int unknown24; /* incremented and set to 2 by FUN_013d03b0 */
};

int FUN_013d03a0(const Object013d03a0 *self) /* derived name */
{
    return self->unknown24 > 1;
}
