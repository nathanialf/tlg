/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkMemorySystem::hkMemorySystem(AllocatorBase *base, AllocatorBase *allocator,
                               AllocatorInterface *allocatorInterface, int flags)
    : baseAllocator(base), frameInfo(0, 32768), allocator18(allocator),
      extended20(allocatorInterface), blockListAllocator(base), flags(flags)
{
}
