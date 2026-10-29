/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Each worker's monitor stream handed out, the count read again after each
 * append (the array may be any memory). */
void Pool00007880::FUN_000077b0(hkArray<MonitorStreamRange> &streamsOut, AllocatorBase &allocator)
{
    for (int i = 0; i < count; i++) {
        MonitorStreamRange &stream = streamsOut.expandOne(allocator);
        stream.begin = workers[i].monitorStreamBegin;
        stream.end = workers[i].monitorStreamEnd;
    }
}
