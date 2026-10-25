/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: the complete destructor of a class with no vtable runs the
 * out-of-line destructor body FUN_00195ff0, which resets the object and
 * frees its arrays at +0x40, +0x30, +0x10 and +0. Its one caller,
 * FUN_00140e70, destroys each object of a pointer array this way before
 * freeing it. Written as a call because neither variant has a name yet. */
struct Object00195ff0; /* derived name */

void FUN_00195ff0(Object00195ff0 *self); /* derived name */

void FUN_00195fe0(Object00195ff0 *self) /* derived name */
{
    FUN_00195ff0(self);
}
