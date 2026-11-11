/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpMaskedShape::FUN_00038130(const hknpShapeSlot29Input &input,
                                  hkGeometry *geometryOut) const /* derived name */
{
    hknpShapeSlot29Input maskedInput = input;
    maskedInput.mask = mask;
    return coreShape->unknownVirtual29(maskedInput, geometryOut);
}
