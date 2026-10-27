/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkp6DofConstraintData::FUN_0017b960(hkpConstraintData::ConstraintInfo &infoOut) const
{
    hkpConstraintData::FUN_00082890(compiledAtoms.data, compiledAtoms.size, infoOut);
    infoOut.add(256, 0, 4);
}
