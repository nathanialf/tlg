/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResourceHandle *hkMemoryResourceContainer::FUN_0017fdb0(const char *handleName,
                                                          hkReferencedObject *object,
                                                          const hkClass *klass)
{
    hkMemoryResourceHandle *handle = new hkMemoryResourceHandle();
    handle->FUN_0017d550(handleName);
    handle->FUN_0017f320(object, klass);
    resourceHandles.pushBack(handle);
    handle->removeReference();
    return handle;
}
