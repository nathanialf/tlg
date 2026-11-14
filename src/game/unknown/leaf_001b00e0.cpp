/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: three functions of the table at 0x168c098 (the third,
 * fifth and seventh of its twelve, from FUN_001afe90; the allocator of
 * user_malloc.c, FUN_001b00c0's file): an allocation, a zeroed array and an
 * aligned allocation. Each takes the block from the space for its size at
 * 0x57c9120 (the second of the two for at most 0x480000 bytes, the first for
 * larger), then from the other, and stops in FUN_001b00c0 when both fail (the
 * module knows it does not return: no return follows the call). */
extern SceLibcMspace D_57c9120[2]; /* derived name: the large space, then the small */

void FUN_001b00c0(); /* derived name: out of memory, does not return */

void *FUN_001b00e0(size_t size) /* derived name */
{
    size_t space = size <= 0x480000;
    for (int attempt = 0; attempt < 2; ++attempt, space ^= 1) {
        if (void *block = sceLibcMspaceMalloc(D_57c9120[space], size))
            return block;
    }
    FUN_001b00c0();
    return 0;
}

void *FUN_001b0170(size_t count, size_t size) /* derived name */
{
    size_t space = size <= 0x480000;
    for (int attempt = 0; attempt < 2; ++attempt, space ^= 1) {
        if (void *block = sceLibcMspaceCalloc(D_57c9120[space], count, size))
            return block;
    }
    FUN_001b00c0();
    return 0;
}

void *FUN_001b02f0(size_t boundary, size_t size) /* derived name */
{
    size_t space = size <= 0x480000;
    for (int attempt = 0; attempt < 2; ++attempt, space ^= 1) {
        if (void *block = sceLibcMspaceMemalign(D_57c9120[space], boundary, size))
            return block;
    }
    FUN_001b00c0();
    return 0;
}
