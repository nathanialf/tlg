/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the size in bytes of what FUN_001accb0 measures in bits:
 * refuses a null result pointer with 0x80d30000 (the code FUN_001accb0
 * gives for its own null pointer), else passes its first argument and its
 * last three on to FUN_001accb0 with a bit count of its own and stores the
 * count divided by 8; returns FUN_001accb0's result. */
static const int kErrorNullPointer = 0x80d30000; /* derived name */

int FUN_001accb0(void *object, u64 *bits, int a, int b, int c); /* derived name */

int FUN_001acc50(void *object, u64 *bytes, int a, int b, int c) /* derived name */
{
    if (!bytes)
        return kErrorNullPointer;
    u64 bits = 0;
    int result = FUN_001accb0(object, &bits, a, b, c);
    *bytes = bits >> 3;
    return result;
}
