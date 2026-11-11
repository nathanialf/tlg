/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldContextPool::Context::FUN_00167d50(hknpWorld *newWorld,
                                                 hkArray<LinkedRange0015ea30> *newCommandRanges,
                                                 BlockStreamAllocator *allocator,
                                                 bool withCommandWriter, bool writeToOwnCache)
{
    world = newWorld;
    modifierManager = newWorld->modifierManager;
    object40 = newWorld->object6b8.pntr;
    qualities = newWorld->qualityLibrary->qualities;
    numQualities = 32;
    materials = newWorld->materialLibrary->entries.elements.data;
    numMaterials = newWorld->materialLibrary->entries.elements.size;
    motionProperties = newWorld->motionPropertiesLibrary->entries.elements.data;
    record220 = HK_NULL;
    pointer240 = HK_NULL;

    cache258 = new BlockCache(newWorld->persistentStreamAllocator);
    cache250 = HK_NULL;
    if (allocator) {
        if (newWorld->persistentStreamAllocator == allocator) {
            cache250 = cache258;
        } else {
            cache250 = new BlockCache(allocator);
        }
    }
    writesToOwnCache = writeToOwnCache;
    cache260 = writeToOwnCache ? cache258 : cache250;

    hknpWorldObject380 *object = static_cast<hknpWorldObject380 *>(modifierManager->objects4e0[0]);
    object->FUN_000310f0(3, records268);

    stream.FUN_00094750(cache258, true);
    commandRanges = newCommandRanges;
    commandWriter = HK_NULL;
    if (withCommandWriter) {
        commandWriter = new hkBlockStreamCommandWriter();
        commandWriter->writer.FUN_000938a0(cache258, &stream);
    }
    triangleShape0 = &triangle0;
    triangleShape1 = &triangle1;
}
