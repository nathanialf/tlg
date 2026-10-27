/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 15 of the memory system's vtable (address point 0x168d690), the
 * base's: the calling thread's router is collected, then what the threads
 * share. */
void hkMemorySystem::garbageCollect()
{
    garbageCollectThread(*D_16dc070);
    garbageCollectShared();
}
