/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpPointToPathConstraintData's destructor (slot 0 of its vtable): the
 * path's reference given back. */
hkpPointToPathConstraintData::~hkpPointToPathConstraintData()
{
    if (path) {
        path->removeReference();
    }
}
