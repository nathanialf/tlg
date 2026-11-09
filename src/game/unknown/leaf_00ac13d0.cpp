/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that clears the bool at +0x18; slot 5 of the
 * vtable at 0x16b35f0 (stored by FUN_00abf490). Slot 6, FUN_00ac13e0, tests the
 * same byte and clears it too. Class and method unknown. */
struct Object00ac13d0 {
    unsigned char unknown0[0x18];
    bool unknown18; /* +0x18 */
};

void FUN_00ac13d0(Object00ac13d0 *self) /* derived name */
{
    self->unknown18 = false;
}
