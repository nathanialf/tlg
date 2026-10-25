/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 4 of AllocatorBase, kept by the allocator vtables
 * 0x168ca00, 0x168e2a0, 0x168e470, 0x16a3230 and 0x16d3318: allocating a
 * buffer of the requested size is allocating a block of it (the size
 * stays as asked). */
void *AllocatorBase::FUN_00008d70(int &numBytes) /* derived name */
{
    return blockAlloc(numBytes);
}
