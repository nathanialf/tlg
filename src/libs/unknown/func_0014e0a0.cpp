/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: the complete destructor (slot 0 of the vtable at
 * 0x16a4390, stored by the constructor FUN_00150240) runs the out-of-line
 * destructor body FUN_0014e100, which stores the same vtable and releases
 * the counted references at +0x190 and +0x188; the deleting destructor
 * FUN_0014e0b0 frees 0x1a0 bytes. Written as a call because neither
 * variant has a name yet. */
struct Object0014e100; /* derived name */

void FUN_0014e100(Object0014e100 *self); /* derived name */

void FUN_0014e0a0(Object0014e100 *self) /* derived name */
{
    FUN_0014e100(self);
}
