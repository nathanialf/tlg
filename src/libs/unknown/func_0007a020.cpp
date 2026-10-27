/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkpPointToPathConstraintData's vtable (address
 * point 0x169bc50): the bridge atoms and the schema the path's solver
 * needs (400 bytes with the 32-byte header, eight solver results and
 * eight temporaries). */
void hkpPointToPathConstraintData::unknownVirtual6(hkpConstraintData::ConstraintInfo &infoOut) const
{
    infoOut.atoms = &atoms;
    infoOut.sizeOfAllAtoms = sizeof(hkpBridgeAtoms);
    infoOut.maxSizeOfSchema = 0;
    infoOut.sizeOfSchemas = 400;
    infoOut.numSolverResults = 8;
    infoOut.numSolverElemTemps = 8;
}
