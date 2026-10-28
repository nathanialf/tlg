/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The index of a block among sorted blocks, or -1 (derived name): the
 * range halved, the key compared with its middle. */
static inline int binarySearch(const void *key, void *const *blocks, int numBlocks)
{
    void *const *base = blocks;
    int n = numBlocks;
    while (n > 0) {
        const int half = n / 2;
        const void *mid = base[half];
        if (mid > key) {
            n = half;
        } else if (mid < key) {
            base += half + 1;
            n -= half + 1;
        } else {
            return int(base - blocks) + half;
        }
    }
    return -1;
}

/* derived name: an allocated block the allocator holds itself is skipped,
 * anything else handed on.
 * NONMATCHING: equal but for the middle element's load, which the base keeps
 * in a register (`mov rax, [r10+rax*8]; cmp rax, rdi`) and this folds into
 * the compare (`cmp [r10+rax*8], rdi`): the peephole optimizer's fold of a
 * load with one use, refused in 3.3 when a DBG_VALUE is a second use (the
 * round 31 `-g` question; docs/NOTES.md, Round 43). */
void FUN_000015c0(void *start, unsigned long size, bool allocated, int pool, void *param)
{
    MemoryWalkFilter000015c0 *filter = static_cast<MemoryWalkFilter000015c0 *>(param);
    if (allocated &&
        binarySearch(start, filter->ownBlocks.data, filter->ownBlocks.getSize()) >= 0) {
        return;
    }
    filter->callback(start, size, allocated, 0, filter->callbackParam);
}
