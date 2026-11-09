/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include <stdlib.h>

/* derived names: releases a block with free. FUN_001db8b0 stores its address
 * at 0x17ac730 beside FUN_00b25420 at 0x17ac728 (which passes an int size,
 * sign-extended, on to malloc as a tail call), the initial values of the same
 * two pointers: an allocation hook pair, the release half, as FUN_0091b760's
 * pair at 0x17ac6a0. */
void FUN_00b25430(void *block) /* derived name */
{
    free(block);
}
