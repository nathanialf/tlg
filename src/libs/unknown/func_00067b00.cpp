/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpMalleableConstraintData's vtable (address
 * point 0x1699aa0): the wrapped data's info, with the malleable atom as the
 * atoms the solver runs. */
void hknpMalleableConstraintData::FUN_00067b00(ConstraintInfo &infoOut) const
{
    constraintData->unknownVirtual6(infoOut);
    infoOut.atoms = &atom;
    infoOut.sizeOfAllAtoms = sizeof(hknpBridgeConstraintAtom);
}
