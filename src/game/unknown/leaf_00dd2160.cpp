/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_013c0030 on the object with the pointer at +0x8 of
 * the record its argument points to, as a tail call; slot 32 of the vtable at
 * 0x16bba90 (its pointer at 0x16bbba0), the vtable stored by FUN_00dd2650
 * FUN_00dd2820 FUN_00dd2890 FUN_00de4790; slot 32 of the vtable at 0x16bc170
 * (its pointer at 0x16bc280), the vtable stored by FUN_00dd2820 FUN_00dd2890
 * FUN_00de43d0 FUN_00de4790 FUN_013c84c0 FUN_013c8500; slot 32 of the vtable
 * at 0x16d2818 (its pointer at 0x16d2928), the vtable stored by FUN_00de43d0.
 * FUN_013c0030 tests that pointer against null. The record, the pointer's
 * target and the return type are not traced. Class and method unknown. */
struct Object00dd2160; /* derived name */
struct Target00dd2160; /* derived name */

struct Argument00dd2160 { /* derived name */
    u8 unknown0[0x8];
    Target00dd2160 *unknown8;
};

void FUN_013c0030(Object00dd2160 *self, Target00dd2160 *value); /* derived name */

void FUN_00dd2160(Object00dd2160 *self, const Argument00dd2160 *argument) /* derived name */
{
    FUN_013c0030(self, argument->unknown8);
}
