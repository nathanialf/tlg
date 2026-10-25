/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived name: converts a string to an unsigned long in a given base,
 * ignoring where the number ends; the parser at 0x19d7d9 reads a byte value
 * from a copied run of digits with it. */
unsigned long FUN_00018010(const char *string, int base)
{
    return _Stoul(string, 0, base);
}
