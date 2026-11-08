/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A large block from the tree bins (dlmalloc's tmalloc_large): the best fit
 * in the size's bin, else the smallest of the next bin in use; taken off its
 * bin, used whole when the rest would be under 256 bytes, else split with
 * the rest put back; the bytes counted. Its payload, or null. derived
 * name. */
void *hkLargeBlockAllocator::FUN_00012620(u64 nb)
{
    Chunk *v = HK_NULL;
    u64 rsize = -int(nb);
    const int idx = treeIndex(nb);
    TreeChunk *t = treebins[idx];
    if (t) {
        u64 sizebits = nb << leftShiftForTreeIndex(idx);
        TreeChunk *rst = HK_NULL;
        for (;;) {
            const u64 trem = (t->head & ~u64(IN_USE_BITS)) - nb;
            if (trem < rsize) {
                v = t;
                if ((rsize = trem) == 0) {
                    break;
                }
            }
            TreeChunk *rt = t->child[1];
            t = t->child[(sizebits >> 63) & 1];
            if (rt != HK_NULL && rt != t) {
                rst = rt;
            }
            if (t == HK_NULL) {
                t = rst;
                break;
            }
            sizebits <<= 1;
        }
    }
    if (t == HK_NULL && v == HK_NULL) {
        const u32 bit = 1u << idx;
        const u32 leftbits = ((bit << 1) | -(bit << 1)) & treemap;
        if (leftbits != 0) {
            const u32 leastbit = leftbits & -leftbits;
            u32 y = leastbit - 1;
            u32 k = y >> (16 - 4) & 16;
            u32 n = k;
            y >>= k;
            n += k = y >> (8 - 3) & 8;
            y >>= k;
            n += k = y >> (4 - 2) & 4;
            y >>= k;
            n += k = y >> (2 - 1) & 2;
            y >>= k;
            n += k = y >> (1 - 0) & 1;
            y >>= k;
            t = treebins[n + y];
        }
    }
    while (t != HK_NULL) {
        const u64 trem = (t->head & ~u64(IN_USE_BITS)) - nb;
        if (trem < rsize) {
            rsize = trem;
            v = t;
        }
        t = t->child[0] ? t->child[0] : t->child[1];
    }
    if (v == HK_NULL) {
        return HK_NULL;
    }
    FUN_00012550(static_cast<TreeChunk *>(v));
    if (rsize < 256) {
        const u64 size = rsize + nb;
        v->head = size | IN_USE_BITS;
        reinterpret_cast<Chunk *>(reinterpret_cast<char *>(v) + size)->head |= PREVIOUS_IN_USE;
        totalBlockBytes += size;
        totalPayloadBytes += size - sizeof(Chunk);
    } else {
        v->head = nb | IN_USE_BITS;
        totalBlockBytes += nb;
        totalPayloadBytes += nb - sizeof(Chunk);
        Chunk *r = reinterpret_cast<Chunk *>(reinterpret_cast<char *>(v) + nb);
        r->head = rsize | PREVIOUS_IN_USE;
        reinterpret_cast<Chunk *>(reinterpret_cast<char *>(r) + rsize)->prevFoot = rsize;
        FUN_00012410(static_cast<TreeChunk *>(r), rsize);
    }
    return reinterpret_cast<char *>(v) + sizeof(Chunk);
}
