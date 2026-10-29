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
    block->pointer10 = allocator;
    block->header.blockIndexInStream = blockIndex;
    blocks.pushBack(block);
    return block;
}

/* The setup appends its first block with the append's statements written
 * out in place: a call to 0x947f0, inlined, would bring the callee's
 * already optimized body, whose block +0x10 GVN then shares across the two
 * clearing paths (a PRE `lea` the base's copy does not have). */
void hkBlockStream::FUN_00094750(BlockCache *cache, hkBool zero)
{
    allocator = cache->allocator;
    numTotalElements = 0;
    partiallyFreed = false;
    zeroNewBlocks = zero;

    hkBlockStreamBlock *block = static_cast<hkBlockStreamBlock *>(cache->FUN_0008eec0());
    if (zeroNewBlocks) {
        hkString::FUN_00018250(block, sizeof(hkBlockStreamBlock));
    } else {
        hkString::memSet16(block, &D_14b2060[2], 2);
    }
    const int blockIndex = blocks.getSize();
    block->pointer10 = allocator;
    block->header.blockIndexInStream = blockIndex;
    blocks.pushBack(block);
}
