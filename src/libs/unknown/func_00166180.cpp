/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpExternMeshShape::~hknpExternMeshShape()
{
    if (FUN_000eafb0()) {
        unknownVirtual8()->shapeDestroyed.fire();
    }
    if (geometry) {
        geometry->removeReference();
        geometry = HK_NULL;
    }
    if (boundingVolumeData) {
        boundingVolumeData->removeReference();
        boundingVolumeData = HK_NULL;
    }
}
