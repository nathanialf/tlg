/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

inline void RouterAllocator50::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
    }
}

/* Nothing to destroy; the deleting destructor (0xac10, slot 1 of the three
 * router allocators' vtables) is the one emitted with it. */
RouterAllocator50::~RouterAllocator50() {}
