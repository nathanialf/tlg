/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpWorldObject388Node *hknpWorldObject380::FUN_0002d790(hknpWorldObject388Node *first,
                                                         hkBlockStreamWriter *const *writer)
{
    hkBlockStreamWriter *const w = *writer;
    const u8 key = first->key;
    hknpWorldObject388Node *node = first;
    do {
        /* A block holds 0xfe0 bytes of data; each one the bytes spill into
         * repeats the node's header (its size read before the loop, so the
         * one zero of the count comes before the guard: MachineSink takes
         * the size's lea into the split edge, 0x2d7c6). */
        int end = w->currentByteOffset + node->numBytes;
        int numHeaderBytes = 0;
        const int blockHeaderBytes = node->numHeaderWords * 4 + 4;
        while (end >= 0xfe0) {
            const int numBlocks = end / 0xfe0;
            const int headerBytes = numBlocks * blockHeaderBytes;
            end = end - numBlocks * 0xfe0 + headerBytes;
            numHeaderBytes += headerBytes;
        }
        node->range.setStartPoint(w);
        w->FUN_000938f0((node->numBytes + numHeaderBytes) / 4, 4);
        node->range.FUN_00092220(w);
        node = static_cast<hknpWorldObject388Node *>(node->next);
        if (!node) {
            return 0;
        }
    } while (node->key == key);
    return node;
}
