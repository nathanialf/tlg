/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that sets bit 4 of the byte at +0x5c of the
 * record its second argument points to; slot 1 of the vtable at 0x16b93b0
 * (the static object at 0x17ac800 holds it; slots 0, 2, 5 and 6 empty, slot 3
 * the library's 0x58a0 returning 1). Class, method and the second record
 * unknown. */
struct Object00cd7ed0; /* derived name */

struct Object00cd7ed0Arg /* derived name */
{
    unsigned char unknown0[0x5c];
    unsigned char flags5c; /* +0x5c, width from the access */
};

void FUN_00cd7ed0(Object00cd7ed0 *self, Object00cd7ed0Arg *other) /* derived name */
{
    other->flags5c |= 0x10;
}
