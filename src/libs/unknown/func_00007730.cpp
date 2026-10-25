/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: a callback that FUN_000076d0 stores at +0x310 of its object
 * (its argument at +0x318); it runs FUN_00017920 on its argument with 0. */
struct Object00017920; /* derived name */

void FUN_00017920(Object00017920 *self, int mode); /* derived name */

void FUN_00007730(Object00017920 *self) /* derived name */
{
    FUN_00017920(self, 0);
}
