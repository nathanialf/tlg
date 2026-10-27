/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpMaskedShape's finish constructor: the decorator shape finishes
 * itself, the mask wrapper is finished inline (its body shares this file)
 * and, on a real finish, pointed back at its shape; the signals, not
 * serialized, start empty. */
hknpMaskedShape::hknpMaskedShape(hkFinishLoadedObjectFlag flag)
    : hknpDecoratorShape(flag), maskWrapper(flag)
{
    if (flag.finishing) {
        maskWrapper.maskedShape = this;
    }
}

/* hknpMaskedShape::MaskWrapper's finish constructor (0x38230): nothing
 * loaded needs fixing up, so only the vtable is set. */
hknpMaskedShape::MaskWrapper::MaskWrapper(hkFinishLoadedObjectFlag flag) : hknpShapeKeyMask(flag) {}
