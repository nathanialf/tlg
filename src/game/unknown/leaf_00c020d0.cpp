/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler that returns 0. FUN_00525530 stores its address at
 * +0x13c0 of the object it constructs (vtable 0x16ab238), index 3 of the
 * +0x13a8 table among its parallel tables of 8-byte handlers (+0x7a8, +0xba8,
 * +0xfa8, +0x13a8); FUN_005f2b90 copies that table with it to its stack.
 * FUN_00be6da0 also stores it at +0x12e0 of its own object (vtable 0x16c8000),
 * index 3 of a table at +0x12c8 (its four tables sit 0xe0 below
 * FUN_00525530's). Typed as its table's siblings FUN_00583950 and
 * FUN_005888f0: the object and a pointer, returning int. Handler unknown. */
int FUN_00c020d0(Owner583950 *self, void *arg) /* derived name */
{
    return 0;
}
