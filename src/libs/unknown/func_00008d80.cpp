/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 5 of AllocatorBase, kept by TwoBaseAllocator,
 * LargeBlockAllocator and four other allocator vtables (0x168ca00,
 * 0x168e470, 0x16a3230, 0x16d3318): freeing a buffer is freeing a block. */
void AllocatorBase::FUN_00008d80(void *pointer, int numBytes) /* derived name */
{
    blockFree(pointer, numBytes);
}
