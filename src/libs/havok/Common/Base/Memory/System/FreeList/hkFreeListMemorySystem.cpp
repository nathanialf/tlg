/* src/libs/havok/Common/Base/Memory/System/FreeList/hkFreeListMemorySystem.cpp:
 * the file its report names (config/homes.base.txt, FUN_0000c590). */
#include "tlg_lib_unknown.h"

/* A thread's router set up by the flags (slot 4): its record taken under the
 * lock, named, its allocator set up and the router's allocators set (1); the
 * stack allocator over the buffer or the heap and the temporary allocator
 * (2). */
void hkFreeListMemorySystem::threadInit(hkMemoryRouter &router, const char *name, int flags)
{
    if (flags & FLAG_ROUTER) {
        int i;
        lock.enter();
        for (i = 0; i < 64; i++) {
            if (!threads[i].inUse) {
                threads[i].inUse = true;
                break;
            }
        }
        lock.leave();
        if (i >= 64) {
            HK_ERROR(0xf03454fe, HK_FREE_LIST_MEMORY_SYSTEM_CPP, 100, "Too many threads");
        }
        ThreadData &thread = threads[i];
        thread.name = name;
        thread.memory.FUN_00014610(allocator18, 8);
        router.allocator50 = HK_NULL;
        AllocatorBase *heap = allocator18;
        if (this->flags & 4) {
            heap = &thread.memory;
        }
        router.temp58 = heap;
        router.allocator60 = &blockListAllocator;
        router.pointer68 = HK_NULL;
        router.userData = reinterpret_cast<void *>(static_cast<hkUlong>(i));
    }
    if (flags & FLAG_TEMPORARY) {
        AllocatorBase *heap;
        if (this->flags & 4) {
            heap = &threads[static_cast<int>(reinterpret_cast<hkUlong>(router.userData))].memory;
        } else {
            heap = allocator18;
        }
        AllocatorBase *slabAllocator = (this->flags & 2) ? &bufferAllocator : heap;
        router.stack.FUN_0000ed60(slabAllocator, heap, heap, frameInfo.second);
        if (this->flags & 1) {
            router.allocator50 = &router.stack;
        } else {
            router.allocator50 = heap;
        }
        router.pointer68 = &bufferAllocator;
    }
}
