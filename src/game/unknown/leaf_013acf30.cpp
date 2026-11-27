/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a region of a pool, 16 bytes: its state in the low four
 * bits of the first byte (0 free, 1 taken, 2 a spare entry) and the bit that
 * lets it grow, its offset, the size taken and its size */
struct Region013acf30 {
    u8 state : 4;
    u8 growable : 1;
    u32 offset; /* +0x4 */
    u32 used;   /* +0x8 */
    u32 size;   /* +0xc */
};

/* derived names: the pool's regions and their count, the size the regions
 * cover and whether a request has failed */
struct Pool013acf30 {
    Region013acf30 *regions; /* +0x0 */
    int count;               /* +0x8 */
    u32 total;               /* +0xc */
    int failed;              /* +0x10 */
};

/* derived name: a region taken for `size`, the rest of it moved to the
 * spare entry after it when there is one */
static inline void take(Pool013acf30 *pool, int index, int size)
{
    if (index < pool->count && pool->regions[index + 1].state == 2) {
        pool->regions[index + 1].state = 0;
        pool->regions[index + 1].growable = pool->regions[index].growable;
        pool->regions[index + 1].offset = pool->regions[index].offset + size;
        pool->regions[index + 1].size = pool->regions[index].size - size;
        pool->regions[index].size = size;
        pool->regions[index].growable = 0;
    }
    pool->regions[index].used = size;
    pool->regions[index].state = 1;
}

// NONMATCHING: the split's test only: the base `cmp eax, r8d; jge` (the index on the
// left), the build `cmp r8d, eax; jle`: IndVars widens the loop's int to i64, the
// index reaching the take is a trunc and InstCombine (getComplexity, a cast 3 against
// a phi 4) puts the count on the left; 74 of 76, 250 bytes as the base
/* derived name: the first free region that holds `size` (a growable one
 * grown to it with four to spare) taken; its index, -1 when none holds it
 * (the pool marked failed) */
int FUN_013acf30(Pool013acf30 *pool, int size)
{
    if (size <= 0)
        return -1;
    for (int i = 0; i < pool->count; ++i) {
        Region013acf30 &region = pool->regions[i];
        if (region.state != 0)
            continue;
        if (region.growable) {
            if (region.size < static_cast<u32>(size)) {
                const u32 grow = size + 4 - region.size;
                pool->total += grow;
                region.size += grow;
            }
        } else if (region.size < static_cast<u32>(size)) {
            continue;
        }
        take(pool, i, size);
        return i;
    }
    if (!pool->failed)
        pool->failed = 1;
    return -1;
}
