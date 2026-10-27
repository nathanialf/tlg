/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a block back to the calling thread's heap, the router's
 * allocator at +0x58 (hkReferencedObject's operator delete and the shared
 * deleting destructors free through it). */
void FUN_0000bcf0(void *block, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(block, static_cast<int>(numBytes));
}
