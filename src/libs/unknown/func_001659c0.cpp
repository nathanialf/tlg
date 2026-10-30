/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the key and the map pointer in r15 and r12 where the base has them in r12 and r15
// (greedy allocates the key first, its interval 16 slots longer than the map pointer's because the
// lea of the map is scheduled after ADJCALLSTACKDOWN64; with the lea first the two tie and the map,
// the lower vreg, goes first, as -pre-RA-sched=source shows); everything else equal (NOTES Round 58B).
void BitFieldMap00199770::FUN_001659c0(u32 bitIndex, u16 key,
                                       void *const &element) /* derived name */
{
    Block *block = fields.FUN_00199520<Block *>(key, 0);
    if (!block || u32(block->bits.storage.numBits) <= bitIndex) {
        Block *newBlock = FUN_00199600(8, numBits, block);
        if (block) {
            FUN_00199770(block);
        }
        fields.FUN_001992f0(hkContainerHeapAllocator::get(), key, newBlock);
        block = newBlock;
    }
    block->bits.set(bitIndex);
    block->elements[bitIndex] = element;
}
