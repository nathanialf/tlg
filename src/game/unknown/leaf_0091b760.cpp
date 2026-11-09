/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include <stdlib.h>

/* derived names: releases a block with free. FUN_0090cfa0 stores its address
 * with that of FUN_0091b750 beside it (which passes an int size, sign-extended,
 * on to the import at 0x14b0288 as a tail call) into a pair of function
 * pointers whose initial values at 0x17ac6a0 and 0x17ac6a8 are the same two
 * functions: an allocation hook pair, the release half. */
void FUN_0091b760(void *block) /* derived name */
{
    free(block);
}
