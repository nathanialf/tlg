/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the allocator's out-of-memory stop: prints "user_malloc.c:
 * Out of Memory!" (the string at 0x155ce00, naming the source file) with puts,
 * calls FUN_001b0570 and stops on a trap (llvm.trap, then the unreachable
 * after it: two ud2 under the target's TrapUnreachable); called by
 * FUN_001b00e0, FUN_001b0170 and the other allocation functions beside it. */
#include "tlg_libc.h"

void FUN_001b0570(); /* derived name */

void FUN_001b00c0() /* derived name */
{
    puts("user_malloc.c: Out of Memory!");
    FUN_001b0570();
    __builtin_trap();
}
