/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The memory setup's objects, built in place in static storage: the large
 * block allocator at 0x57af810, the free-list allocator over it at
 * 0x57af9c0 and the memory system at 0x57b0520. derived names. */
static char D_57af810[sizeof(LargeBlockAllocator)];
static char D_57af9c0[sizeof(TwoBaseAllocator)];
static char D_57b0520[sizeof(hkMemorySystem)];

/* The two allocators, recorded for the quit function. */
static LargeBlockAllocator *D_57b7490;
static TwoBaseAllocator *D_57b7498;

/* derived name: the quit function the setup stores at 0x57b99e8: each
 * allocator destroyed in place, the one built last first, and forgotten. */
void FUN_00001200() /* derived name */
{
    if (D_57b7498) {
        D_57b7498->~TwoBaseAllocator();
        D_57b7498 = 0;
    }
    if (D_57b7490) {
        D_57b7490->~LargeBlockAllocator();
        D_57b7490 = 0;
    }
}

/* derived name: the memory setup the game runs (0xe99650): the large block
 * allocator over the base allocator, the free-list allocator over it, the
 * memory system over both, installed and set up with the sizes. */
hkResult FUN_00001140(AllocatorBase *base, const SizePair00006c30 &sizes,
                      const TwoBaseAllocatorCinfo *cinfo, int flags) /* derived name */
{
    LargeBlockAllocator *large = new (D_57af810) LargeBlockAllocator(base);
    TwoBaseAllocator *freeList = new (D_57af9c0) TwoBaseAllocator(large, large, cinfo);
    hkMemorySystem *system = new (D_57b0520) hkMemorySystem(base, freeList, freeList, flags);
    D_57b99e0 = system;
    D_57b7490 = large;
    D_57b7498 = freeList;
    FUN_00006c40(system);
    D_57b99e8 = FUN_00001200;
    return system->FUN_0000c490(sizes, 3);
}
