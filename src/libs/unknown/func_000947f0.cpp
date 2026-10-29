/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkBlockStreamBlock *hkBlockStream::FUN_000947f0(BlockCache *cache)
{
    hkBlockStreamBlock *block = static_cast<hkBlockStreamBlock *>(cache->FUN_0008eec0());
    if (zeroNewBlocks) {
        hkString::FUN_00018250(block, sizeof(hkBlockStreamBlock));
    } else {
        hkString::memSet16(block, &D_14b2060[2], 2);
    }
    const int blockIndex = blocks.getSize();
    block->pointer10 = pointer0;
    block->header.blockIndexInStream = blockIndex;
    blocks.pushBack(block);
    return block;
}
