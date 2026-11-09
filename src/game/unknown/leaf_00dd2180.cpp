/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_013bfc40 on the object with the pointer at +0x8 of
 * the record its argument points to, as a tail call; slot 34 of the vtable at
 * 0x16bba90 (its pointer at 0x16bbbb0), the vtable stored by FUN_00dd2650
 * FUN_00dd2820 FUN_00dd2890 FUN_00de4790; slot 34 of the vtable at 0x16bc170
 * (its pointer at 0x16bc290), the vtable stored by FUN_00dd2820 FUN_00dd2890
 * FUN_00de43d0 FUN_00de4790 FUN_013c84c0 FUN_013c8500; slot 34 of the vtable
 * at 0x16d2818 (its pointer at 0x16d2938), the vtable stored by FUN_00de43d0.
 * FUN_013bfc40 tests that pointer against null. The record, the pointer's
 * target and the return type are not traced. Class and method unknown. */
struct Object00dd2180; /* derived name */
struct Target00dd2180; /* derived name */

struct Argument00dd2180 { /* derived name */
    u8 unknown0[0x8];
    Target00dd2180 *unknown8;
};

void FUN_013bfc40(Object00dd2180 *self, Target00dd2180 *value); /* derived name */

void FUN_00dd2180(Object00dd2180 *self, const Argument00dd2180 *argument) /* derived name */
{
    FUN_013bfc40(self, argument->unknown8);
}
