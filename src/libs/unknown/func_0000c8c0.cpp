/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The entries emptied, then one for each of the system's allocators: the
 * base, the heap, the debug interface's and the solver's buffer. */
void hkFreeListMemorySystem::getMemoryStatistics(hkArray<MemoryStatisticsEntry> &entries)
{
    entries.clear();
    MemoryStatisticsEntry &system = entries.expandOne();
    system.allocatorName = "System";
    baseAllocator->getMemoryStatistics(system.allocatorStatistics);
    MemoryStatisticsEntry &heap = entries.expandOne();
    heap.allocatorName = "Heap";
    allocator18->getMemoryStatistics(heap.allocatorStatistics);
    MemoryStatisticsEntry &debug = entries.expandOne();
    debug.allocatorName = "Debug";
    blockListAllocator.getMemoryStatistics(debug.allocatorStatistics);
    MemoryStatisticsEntry &solver = entries.expandOne();
    solver.allocatorName = "Solver";
    bufferAllocator.getMemoryStatistics(solver.allocatorStatistics);
}
