/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkpPointToPathConstraintData's vtable (address
 * point 0x169bc50): the data is usable once it has a path and a valid
 * orientation constraint. */
hkBool hkpPointToPathConstraintData::unknownVirtual7() const
{
    return path != 0 && angularConstrainedDOF != CONSTRAIN_ORIENTATION_INVALID;
}
