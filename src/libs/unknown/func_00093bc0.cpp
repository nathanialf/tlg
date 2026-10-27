/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the block goes back to the stream's cache when every one
 * of its elements was consumed; otherwise the consumed ones leave its count
 * (other consumers may still hold the block). */
void hkBlockStreamConsumedBlock::FUN_00093bc0()
{
    if (stream) {
        hkBlockStreamBlock *b = block;
        const hkBlockStreamBlock::Header header = b->getHeader();
        if (int(header.numElementsAndBytesUsed & 0xffff) == numElementsConsumed) {
            stream->FUN_00094df0(cache, b, header.blockIndexInStream);
        } else {
            __sync_fetch_and_sub(&b->header.numElementsAndBytesUsed, numElementsConsumed);
        }
    }
}
