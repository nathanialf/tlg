/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpExternMeshShape's vtable (address point
 * 0x16a5180; the same body fills the vtable slot at 0x16ca090):
 * the mutation signals of its data's build context, null without one. */
hknpShapeSignals *hknpExternMeshShape::FUN_000eafb0()
{
    Object000ea380 *context = boundingVolumeData->buildContext;
    return context ? &context->mutationSignals : 0;
}
