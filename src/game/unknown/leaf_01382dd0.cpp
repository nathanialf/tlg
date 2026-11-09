/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 5 of the vtable at 0x16cd348 (stored by FUN_00991430
 * FUN_00991560 FUN_00991670 FUN_00e5b650 FUN_01382c30 FUN_01382d00) returns
 * the address of the pointer at +0x28; the destructor FUN_01382c30 frees the
 * block it points to (through its allocator when the header byte at -0x10 is
 * 10, else free). Class and method unknown. */
struct Object01382c30 /* derived name */
{
    unsigned char unknown0[0x28];
    void *block; /* +0x28 */
};

void **FUN_01382dd0(Object01382c30 *self) /* derived name */
{
    return &self->block;
}
