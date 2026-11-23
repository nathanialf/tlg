/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_sce_kernel.h"

/* derived names: a block of the allocator whose messages begin
 * "[Gomalloc] " (FUN_012fdf60's): its size at +0x8, the next at +0x10 */
struct GomallocBlock012fe750 { /* derived name */
    u8 unknown0[0x8];
    u64 size;                    /* +0x8 */
    GomallocBlock012fe750 *next; /* +0x10 */
};

/* derived names: the allocator: two lists of blocks at +0x70 and +0x80 and
 * the mutex at +0xa0 its functions hold */
struct Gomalloc012fe750 { /* derived name */
    u8 unknown0[0x70];
    GomallocBlock012fe750 *blocks70; /* +0x70 */
    u8 unknown78[0x8];
    GomallocBlock012fe750 *blocks80; /* +0x80 */
    u8 unknown88[0x18];
    pthread_mutex_t mutex; /* +0xa0 */
};

/* derived names: the sizes of all the blocks, of the second list's alone,
 * and the number of blocks */
struct GomallocSizes012fe750 { /* derived name */
    u64 total;
    u64 total80; /* +0x8 */
    u64 count;   /* +0x10 */
};

/* derived name: the allocator's blocks counted and summed under its mutex */
void FUN_012fe750(Gomalloc012fe750 *heap, GomallocSizes012fe750 *sizes) /* derived name */
{
    int rc = scePthreadMutexLock(&heap->mutex);
    if (rc < 0) {
        printf("[Gomalloc] ");
        printf("scePthreadMutexLock(&mutex) failed %08x\n", rc);
    }
    if (heap) {
        u64 total = 0;
        unsigned count = 0;
        for (GomallocBlock012fe750 *block = heap->blocks70; block; block = block->next) {
            total += block->size;
            ++count;
        }
        u64 total80 = 0;
        for (GomallocBlock012fe750 *block = heap->blocks80; block; block = block->next) {
            ++count;
            total80 += block->size;
            total += block->size;
        }
        sizes->total = total;
        sizes->total80 = total80;
        sizes->count = count;
    }
    rc = scePthreadMutexUnlock(&heap->mutex);
    if (rc < 0) {
        printf("[Gomalloc] ");
        printf("scePthreadMutexUnlock has returned %08x\n", rc);
    }
}
