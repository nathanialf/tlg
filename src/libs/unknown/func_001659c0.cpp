/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Each grow path hands its new field to the map itself (the two insert calls
 * are one in the executable, merged by the tail merge after register
 * allocation, so the key and the map pointer each end in both paths); the
 * element's slot is taken before the element is read. */
void BitFieldMap00199770::FUN_001659c0(u32 bitIndex, u16 key,
                                       void *const &element) /* derived name */
{
    Block *block = fields.FUN_00199520<Block *>(key, 0);
    if (!block) {
        block = FUN_00199600(8, numBits, HK_NULL);
        fields.FUN_001992f0(hkContainerHeapAllocator::get(), key, block);
    } else if (u32(block->bits.storage.numBits) <= bitIndex) {
        Block *newBlock = FUN_00199600(8, numBits, block);
        FUN_00199770(block);
        fields.FUN_001992f0(hkContainerHeapAllocator::get(), key, newBlock);
        block = newBlock;
    }
    block->bits.set(bitIndex);
    void **slot = &block->elements[bitIndex]; /* derived name */
    *slot = element;
}
