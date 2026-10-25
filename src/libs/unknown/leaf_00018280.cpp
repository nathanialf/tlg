/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: an ordering of pointers by address, passed as the
 * comparison function to the sort FUN_00018290 by its one caller (0x18af4),
 * which sorts an array of pointers. */
bool FUN_00018280(const void *a, const void *b) /* derived name */
{
    return a < b;
}
