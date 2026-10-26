/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 16 of hkpLimitedHingeConstraintData's vtable (address
 * point 0x169bae0) sets the solving method: the stabilized method enables
 * the stabilization atom, the old one disables it. */
void hkpLimitedHingeConstraintData::FUN_000792a0(hkpConstraintAtom::SolvingMethod method)
{
    switch (method) {
    case hkpConstraintAtom::METHOD_STABILIZED:
        atoms.setupStabilization.enabled = true;
        atoms.ballSocket.solvingMethod = hkpConstraintAtom::METHOD_STABILIZED;
        break;
    case hkpConstraintAtom::METHOD_OLD:
        atoms.setupStabilization.enabled = false;
        atoms.ballSocket.solvingMethod = hkpConstraintAtom::METHOD_OLD;
        break;
    }
}
