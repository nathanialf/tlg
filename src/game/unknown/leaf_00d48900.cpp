/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that sets bit 18 of the flags word at +0x24
 * (the compiler narrows the store to bit 2 of the byte at +0x26); slot 8 of
 * the vtable at 0x16ba510 (stored by FUN_00d48670), whose slot 7 FUN_00c59010 tests bit 1
 * of the same word. The record is the base whose destructor is FUN_00c55550
 * (which reads and writes the word as an int); class and method unknown. */
struct Object00c55550 /* derived name */
{
    unsigned char unknown0[0x24];
    unsigned int flags; /* +0x24 */
};

void FUN_00d48900(Object00c55550 *self) /* derived name */
{
    self->flags |= 0x40000;
}
