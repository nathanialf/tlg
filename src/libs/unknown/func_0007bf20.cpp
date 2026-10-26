/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkpFixedConstraintData's vtable (address point 0x169c630; also hkpHingeConstraintData's):
 * the constraint's info from its atoms, by the shared FUN_00082890. */
void hkpFixedConstraintData::FUN_0007bf20(hkpConstraintData::ConstraintInfo &infoOut) const
{
    hkpConstraintData::FUN_00082890(&atoms, sizeof(Atoms), infoOut);
}
