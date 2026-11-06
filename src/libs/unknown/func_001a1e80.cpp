/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 120 of 124, the local array's constructor stores only: the base
// stores the data, the capacity, then the local memory (Havok's hkLocalArray
// order, 0x1a1f06 to 0x1a1f15), the tree's LocalArray stores the local memory
// before the capacity, which the claimed 0x1707d0 needs (cookbook 371:
// InstCombine's forwarding of the capacity, FindAvailableLoadedValue with no
// alias analysis, Loads.cpp:176-200). A form of 0x1707d0 over the Havok order
// is the open question (NOTES "Round 73B").
void FUN_001a1e80(hkStreamWriter *writer, int alignment)
{
    const int position = writer->tell();
    LocalArray<char> zeros(alignment);
    zeros.setSize(hkContainerHeapAllocator::get(), alignment, 0);
    const int misalignment = position & (alignment - 1);
    if (misalignment) {
        writer->write(zeros.data, alignment - misalignment);
    }
}
