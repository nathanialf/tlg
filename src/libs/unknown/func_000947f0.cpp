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

// NONMATCHING: the base runs 0x947f0 in place here, the compile tail-calls
// it: its inline cost is 240 to 245 (measured with -inline-threshold, scratch
// only) against -O2's 225, so the base's call carried the inline hint (325,
// D21's addendum) or a cheaper body. An inline helper under both (the
// keyword on it) inlines in both, but GVN's scalar PRE then gives the block's
// +0x10 its own `lea` in both (the helper's second GVN), which neither base
// copy has (docs/NOTES.md, Round 53).
void hkBlockStream::FUN_00094750(BlockCache *cache, hkBool zero)
{
    allocator = cache->allocator;
    numTotalElements = 0;
    partiallyFreed = false;
    zeroNewBlocks = zero;
    FUN_000947f0(cache);
}
