/* src/game/user_malloc.cpp: the allocator's file. Its name is the base's: the
 * out-of-memory message at 0x155ce00 reads "user_malloc.c: Out of Memory!".
 * The functions written so far, in the base's order; they are one unit
 * because the base shows it: the allocation functions call the
 * out-of-memory stop where a link stage that met it in another unit would
 * have inlined it (its unit already knew it does not return). */
#include "tlg_libc.h"
#include "tlg_sce_kernel.h"

void FUN_001b0570(); /* derived name */

/* derived names: the three allocation functions take the block from the
 * space for its size at 0x57c9120 (the second of the two for at most
 * 0x480000 bytes, the first for larger), then from the other, and stop in
 * FUN_001b00c0 when both fail. */
extern SceLibcMspace D_57c9120[2]; /* derived name: the large space, then the small */

/* derived names: what the table's first function (FUN_001afe90) sets up:
 * whether it took the direct memory and the flexible memory, and where each
 * starts */
extern bool D_57c9108;  /* derived name: the direct memory taken */
extern bool D_57c9109;  /* derived name: the flexible memory taken */
extern long D_57c9110;  /* derived name: the direct memory's start */
extern void *D_57c9118; /* derived name: the flexible memory's address */

/* derived name: the second function of the table at 0x168c098: the two
 * spaces destroyed (each one left, and 1 returned, when it cannot be), then
 * the direct memory (0x69800000 bytes) and the flexible memory (0x11800000
 * bytes) given back, a length of 0 for memory not taken; 1 when either
 * fails. */
// NONMATCHING: the two flags: the base reads each as a byte masked to one bit (`mov al, [0x57c9108];
// and al, 1; cmovne`), the form of a file static GlobalOpt has shrunk to a bool because every store
// to it is in this unit (FUN_001afe90 stores 1 to both, `mov byte [0x57c9108], 1`); declared here
// until that function is written, the build compares the byte (`cmp byte [..], 0; jne`)
int FUN_001b0020() /* derived name */
{
    for (int space = 0; space < 2; ++space) {
        if (D_57c9120[space]) {
            if (sceLibcMspaceDestroy(D_57c9120[space]) != 0)
                return 1;
            D_57c9120[space] = 0;
        }
    }
    if (sceKernelReleaseDirectMemory(D_57c9110, D_57c9108 ? 0x69800000 : 0) < 0)
        return 1;
    return sceKernelReleaseFlexibleMemory(D_57c9118, D_57c9109 ? 0x11800000 : 0) < 0;
}

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

/* derived name: the first address of the small space; a block at or above it
 * is the small space's (FUN_001b0140) */
extern void *D_57c9100;

/* derived name: the fourth function of the table at 0x168c098: the block
 * freed into the space that holds it */
void FUN_001b0140(void *block) /* derived name */
{
    sceLibcMspaceFree(D_57c9120[block >= D_57c9100], block);
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

/* derived name: the sixth function of the table at 0x168c098: the
 * reallocation: a size of 0 frees the block, no block is an allocation; else
 * the new block, the old one's usable size or the new size, whichever is
 * less, copied, and the old block freed */
void *FUN_001b01e0(void *block, size_t size) /* derived name */
{
    if (size == 0) {
        FUN_001b0140(block);
        return 0;
    }
    if (block) {
        void *moved = FUN_001b00e0(size);
        size_t used = sceLibcMspaceMallocUsableSize(block);
        memcpy(moved, block, used < size ? used : size);
        FUN_001b0140(block);
        return moved;
    }
    size_t space = size <= 0x480000;
    for (int attempt = 0; attempt < 2; ++attempt, space ^= 1) {
        if (void *moved = sceLibcMspaceMalloc(D_57c9120[space], size))
            return moved;
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

/* derived name: the ninth function of the table at 0x168c098: an aligned
 * block, by the semantics of posix_memalign, from the space the pointer it
 * replaces lies in, then from the other */
int FUN_001b0360(void **block, size_t boundary, size_t size) /* derived name */
{
    size_t space = *block >= D_57c9100;
    for (int attempt = 0; attempt < 2; ++attempt, space ^= 1) {
        int result = sceLibcMspacePosixMemalign(D_57c9120[space], block, boundary, size);
        if (*block)
            return result;
    }
    FUN_001b00c0();
    return 0;
}

/* derived name: the eighth function of the table at 0x168c098: the
 * reallocation with an alignment: as FUN_001b01e0, the new block aligned
 * (no block is a plain allocation) */
void *FUN_001b03e0(void *block, size_t size, size_t boundary) /* derived name */
{
    if (size == 0) {
        FUN_001b0140(block);
        return 0;
    }
    if (block == 0)
        return FUN_001b00e0(size);
    void *moved = FUN_001b02f0(boundary, size);
    size_t used = sceLibcMspaceMallocUsableSize(block);
    memcpy(moved, block, used < size ? used : size);
    FUN_001b0140(block);
    return moved;
}

/* derived names: the statistics of the large space, the tenth and eleventh
 * functions of the table at 0x168c098 */
int FUN_001b0520(SceLibcMallocManagedSize *stats) /* derived name */
{
    return sceLibcMspaceMallocStats(D_57c9120[0], stats);
}

int FUN_001b0540(SceLibcMallocManagedSize *stats) /* derived name */
{
    return sceLibcMspaceMallocStatsFast(D_57c9120[0], stats);
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
