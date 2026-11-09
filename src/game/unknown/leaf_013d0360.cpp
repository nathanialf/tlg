/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method adding one to the int at +0x8, slot 2 of the
 * vtables at 0x16d3800 (stored by FUN_00f39850 FUN_00f40940), 0x16d3d48
 * (stored by FUN_00f7d610) and 0x16d6a10 (stored by FUN_01203d30), whose slot 4 is FUN_00010650 returning that int and
 * slot 1 the shared deleting destructor FUN_00021a00. The 32-bit increment
 * gives the width; int is not traced further. */
struct Object013d0360 {
    u8 unknown0[0x8];
    int unknown8;
};

void FUN_013d0360(Object013d0360 *self) /* derived name */
{
    ++self->unknown8;
}
