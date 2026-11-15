/* src/game/user_malloc.cpp: the allocator's file. Its name is the base's: the
 * out-of-memory message at 0x155ce00 reads "user_malloc.c: Out of Memory!".
 * The functions written so far, in the base's order; they are one unit
 * because the base shows it: the allocation functions call the
 * out-of-memory stop where a link stage that met it in another unit would
 * have inlined it (its unit already knew it does not return). */
#include "tlg_libc.h"

void FUN_001b0570(); /* derived name */

/* derived names: the three allocation functions take the block from the
 * space for its size at 0x57c9120 (the second of the two for at most
 * 0x480000 bytes, the first for larger), then from the other, and stop in
 * FUN_001b00c0 when both fail. */
extern SceLibcMspace D_57c9120[2]; /* derived name: the large space, then the small */

/* derived name: the allocator's out-of-memory stop: prints the message with
 * puts, calls FUN_001b0570 and stops on a trap (llvm.trap, then the
 * unreachable after it: two ud2 under the target's TrapUnreachable); called
 * by FUN_001b00e0, FUN_001b0170 and the other allocation functions beside
 * it. */
void FUN_001b00c0() /* derived name */
{
    puts("user_malloc.c: Out of Memory!");
    FUN_001b0570();
    __builtin_trap();
}

/* derived names: three functions of the table at 0x168c098 (the third,
 * fifth and seventh of its twelve, from FUN_001afe90): an allocation, a
 * zeroed array and an aligned allocation. */
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

/* derived name: the twelfth and last function of the table at 0x168c098
 * (its size 0x70 and the int 1 first, then twelve functions from
 * FUN_001afe90; the next table, at 0x168c108, carries 2): the usable size of
 * a block, passed on to the C library. Its neighbours FUN_001b0520 and
 * FUN_001b0540 pass the space at 0x57c9120 with their argument. */
size_t FUN_001b0560(void *block) /* derived name */
{
    return sceLibcMspaceMallocUsableSize(block);
}
