/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A buffer of a new size: the old one given back to the router's heap when
 * the stream allocated it, then a new one of the size the heap grants, the
 * last command's place 32 bytes before its end. */
void ThreadBuffer::FUN_0000eb90(int size)
{
    if (size == capacity - start) {
        return;
    }
    if (start && isBufferAllocatedOnTheHeap) {
        D_16dc070->allocator60->FUN_00008d80(start, int(capacity - start));
    }
    isBufferAllocatedOnTheHeap = false;
    start = 0;
    end = 0;
    capacity = 0;
    capacityMinus16 = 0;
    if (size > 0) {
        isBufferAllocatedOnTheHeap = true;
        AllocatorBase *heap = D_16dc070->allocator60;
        int numBytes = size;
        char *const buffer = static_cast<char *>(heap->FUN_00008d70(numBytes));
        char *const bufferEnd = buffer + numBytes;
        start = buffer;
        end = buffer;
        capacity = bufferEnd;
        capacityMinus16 = bufferEnd - 32;
    }
}
