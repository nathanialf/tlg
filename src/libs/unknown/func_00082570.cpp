/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkpPulleyConstraintData's vtable (address point 0x169f600):
 * the constraint's info from its atoms, by the shared FUN_00082890. */
void hkpPulleyConstraintData::FUN_00082570(hkpConstraintData::ConstraintInfo &infoOut) const
{
    hkpConstraintData::FUN_00082890(&atoms, sizeof(Atoms), infoOut);
}
