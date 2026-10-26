/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpConstraintData's finish constructor, run by the finish constructors of
 * the constraint data classes: nothing loaded needs fixing up, so only the
 * vtable is set. */
hkpConstraintData::hkpConstraintData(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
