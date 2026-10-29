/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpPointToPathConstraintData::setPath(hkpParametricCurve *newPath)
{
    if (newPath) {
        newPath->addReference();
    }
    if (path) {
        path->removeReference();
    }
    path = newPath;
}
