/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: a virtual method that returns 0, the body behind 439 vtable
 * slots in .data.rel.ro (from 0x168c1d8). The code at 0xb768 calls it directly
 * with a buffer, the size 0x80 and 0, and compares the int result against 3;
 * 0x57d0 stores its address as a callback in a table of records. Class and
 * method unknown. */
struct Object000042d0;

int FUN_000042d0(Object000042d0 *self) /* derived name */
{
    return 0;
}
