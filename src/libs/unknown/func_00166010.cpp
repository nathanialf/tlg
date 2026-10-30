/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpExternMeshShape::hknpExternMeshShape(const Geometry *geometry_, hknpExternMeshShapeData *data)
{
    geometry = geometry_;
    geometry_->addReference();
    boundingVolumeData = data;
    data->addReference();
    numShapeKeyBits = 0;
    for (int n = geometry->unknownVirtual5(); n > 0; n >>= 1) {
        numShapeKeyBits++;
    }
    flags |= NO_GET_SHAPE_KEYS_ON_SPU | SHAPE_NOT_SUPPORTED_ON_SPU;
}
