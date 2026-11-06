/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* With a mass configuration, the mass properties are kept compressed under
 * key 0xf100: in the object already there or a new one, whose own
 * reference is released once the properties hold it. */
hknpStaticCompoundShape::hknpStaticCompoundShape(const hknpCompoundShapeCinfo &cinfo)
    : hknpCompoundShape(cinfo), boundingVolumeData(HK_NULL)
{
    FUN_000cfca0();
    updateAabb();
    if (cinfo.unknown18) {
        hkDiagonalizedMassProperties massProperties;
        unknownVirtual28(cinfo.unknown18, &massProperties);
        hknpShapeMassProperties *shapeMassProperties =
            static_cast<hknpShapeMassProperties *>(getProperty(0xf100));
        const bool kept = shapeMassProperties != HK_NULL;
        if (!kept) {
            shapeMassProperties = new hknpShapeMassProperties();
        }
        shapeMassProperties->compressedMassProperties.FUN_00026100(massProperties);
        setProperty(0xf100, shapeMassProperties);
        if (!kept) {
            shapeMassProperties->removeReference();
        }
    }
}
