/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 17 of 72, the header count's loop: the compile zeroes the
// count again in the loop's preheader (`xor ecx, ecx` after `lea eax,
// [rax*4+4]`), which moves the loop to the next 16 bytes and assigns the
// per-block bytes to eax where the base keeps one zero, from before the
// guard, and the per-block bytes in edi; the range's start and the run's
// walk are the base's (docs/NOTES.md, Round 60A).
hknpWorldObject388Node *hknpWorldObject380::FUN_0002d790(hknpWorldObject388Node *first,
                                                         hkBlockStreamWriter *const *writer)
{
    hkBlockStreamWriter *const w = *writer;
    const u8 key = first->key;
    hknpWorldObject388Node *node = first;
    do {
        /* A block holds 0xfe0 bytes of data; each one the bytes spill into
         * repeats the node's header. */
        int end = w->currentByteOffset + node->numBytes;
        int numHeaderBytes = 0;
        while (end >= 0xfe0) {
            const int numBlocks = end / 0xfe0;
            end -= numBlocks * 0xfe0;
            const int headerBytes = numBlocks * (node->numHeaderWords * 4 + 4);
            end += headerBytes;
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
