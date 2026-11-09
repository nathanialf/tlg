/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that calls FUN_013bf850 on the object with
 * the pointer its argument points to as a tail call; slot 39 of the vtable at
 * 0x16bba90 (its pointer at 0x16bbbd8), the vtable stored by FUN_00dd2650
 * FUN_00dd2820 FUN_00dd2890 FUN_00de4790; slot 39 of the vtable at 0x16bc170
 * (its pointer at 0x16bc2b8), the vtable stored by FUN_00dd2820 FUN_00dd2890
 * FUN_00de43d0 FUN_00de4790 FUN_013c84c0 FUN_013c8500; slot 39 of the vtable
 * at 0x16d2818 (its pointer at 0x16d2960), the vtable stored by FUN_00de43d0.
 * The pointer's target and the return type are not traced. Class and method
 * unknown. */
struct Object00dd2580;
struct Target00dd2580; /* derived name */

void FUN_013bf850(Object00dd2580 *self, Target00dd2580 *value); /* derived name */

void FUN_00dd2580(Object00dd2580 *self, Target00dd2580 *const *value) /* derived name */
{
    FUN_013bf850(self, *value);
}
