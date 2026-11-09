/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>

/* derived names: allocates a block with malloc, its int size sign-extended
 * (`movsxd rdi, edi`) as a tail call. FUN_0090cfa0 stores its address with
 * that of FUN_0091b760 beside it (which releases a block with free) into a
 * pair of function pointers whose initial values at 0x17ac6a0 and 0x17ac6a8
 * are the same two functions: an allocation hook pair, the allocation half. */
void *FUN_0091b750(int size) /* derived name */
{
    return malloc(size);
}
