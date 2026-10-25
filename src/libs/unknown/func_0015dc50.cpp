/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: the complete destructor (slot 0 of the vtable at
 * 0x16a4ee0) of a class with a second polymorphic base at +0x10 runs the
 * out-of-line destructor body FUN_0015dee0, which stores both vtables and
 * destroys the 0x710-byte elements of the array at +0x108; the deleting
 * destructor FUN_0015dc60 frees 0x170 bytes, and 0x15dcb0 enters the body
 * from the second base. Written as a call because neither variant has a
 * name yet. */
struct Object0015dee0; /* derived name */

void FUN_0015dee0(Object0015dee0 *self); /* derived name */

void FUN_0015dc50(Object0015dee0 *self) /* derived name */
{
    FUN_0015dee0(self);
}
