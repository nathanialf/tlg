/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include <stdlib.h>

/* derived names: an allocation hook pair, the initial values of the function
 * pointers at 0x57ad990 and 0x57ad998 (FUN_00ed19c0 and others call through
 * them; FUN_00eb45d0 replaces both with FUN_00ebf3a0 and FUN_00ebf3f0). The
 * allocation half passes its 64-bit size on to malloc, the release half its
 * block on to free, each as a tail call. */
void *FUN_00f02650(size_t size) /* derived name */
{
    return malloc(size);
}

void FUN_00f02660(void *block) /* derived name */
{
    free(block);
}
