/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: slot 6 of an interface whose destructor is the shared empty
 * body (slot 0, FUN_0003b640) and whose deleting destructor is FUN_0000d900:
 * the base's default implementation, never overridden in the twelve vtables
 * that carry it (0x169a5a0, 0x16a4570, 0x16a4850, ...). It hands back its
 * last argument, the second passed on the stack, unchanged. Class, method
 * and the types of the other arguments unknown. */
struct Object00069440;

int FUN_00069440(Object00069440 *self, const void *, const void *, const void *, const void *,
                 const void *, const void *, int count) /* derived name */
{
    return count;
}
