/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: allocates a block with malloc, its int size sign-extended
 * (`movsxd rdi, edi`) as a tail call. FUN_0090cfa0 stores its address at
 * 0x17ac728 (lea at 0x90d1a9), beside FUN_00b25430, which releases a block
 * with free, as it stores FUN_0091b750 and FUN_0091b760 (the same pair of
 * bodies) at 0x17ac6a0 and 0x17ac6a8: a second allocation hook pair, the
 * allocation half. */
#include <stdlib.h>

void *FUN_00b25420(int size) /* derived name */
{
    return malloc(size);
}
