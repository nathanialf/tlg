/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: a callback that slot 5 of Pool00007880's vtable (0x7660)
 * stores at +0x310 of its object (its argument at +0x318), run by each
 * worker of the pool (0x7316) on that argument; it runs FUN_00005fc0 on the
 * argument with its flag set. */
struct Object00005fc0; /* derived name */

void FUN_00005fc0(Object00005fc0 *self, bool flag); /* derived name */

void FUN_000076c0(Object00005fc0 *self) /* derived name */
{
    FUN_00005fc0(self, true);
}
