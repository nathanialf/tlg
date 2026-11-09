/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 6 of the vtable at 0x16b01f0 (stored by FUN_008c1650
 * FUN_008c17c0) returns the address of the int at +0x38; the destructor
 * FUN_008c17c0 releases the ints at +0x2c to +0x38 through FUN_00d66e30 as
 * handles, and slot 5 FUN_01373a50 looks the one at +0x34 up in a table of
 * 32-byte entries. Class and method unknown. */
struct Object008c17c0 /* derived name */
{
    unsigned char unknown0[0x38];
    int handle38; /* +0x38 */
};

int *FUN_01373a70(Object008c17c0 *self) /* derived name */
{
    return &self->handle38;
}
