/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkUuidObject's finish constructor: a loaded uuid needs no fixing up, so
 * only the vtable is set. */
hkUuidObject::hkUuidObject(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
