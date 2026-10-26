/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a block from the calling thread's heap, the router's
 * allocator at +0x58 (hkReferencedObject's operator new). The
 * size comes as operator new's and the allocator takes an int. */
void *FUN_0000bcc0(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}
