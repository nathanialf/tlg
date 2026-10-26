/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpMaskedShape::MaskWrapper's finish constructor: nothing loaded needs
 * fixing up, so only the vtable is set. */
hknpMaskedShape::MaskWrapper::MaskWrapper(hkFinishLoadedObjectFlag flag) : hknpShapeKeyMask(flag) {}
