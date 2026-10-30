/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int MemorySnapshot00011280::FUN_00011170(const char *name, int parentId)
{
    const int id = providers.getSize();
    if (providers.getSize() == providers.getCapacity()) {
        FUN_00000b40(*allocator, &providers, sizeof(Provider));
    }
    hkArrayUtil::construct(providers.data + providers.size);
    Provider &provider = providers.data[providers.size++];
    FUN_00017fd0(provider.name, name, sizeof(provider.name) - 1);
    provider.name[sizeof(provider.name) - 1] = '\0';
    if (parentId != -1) {
        provider.parentIndices.pushBack(*allocator, parentId);
    }
    return id;
}
