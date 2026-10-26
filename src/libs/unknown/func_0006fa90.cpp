/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpShape's finish constructor: nothing loaded needs fixing up, so only
 * the vtable is set. */
hknpShape::hknpShape(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
