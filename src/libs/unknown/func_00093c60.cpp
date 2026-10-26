/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkGeometry's finish constructor: the arrays are loaded in place, so only
 * the vtable is set. */
hkGeometry::hkGeometry(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
