/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkpPointToPathConstraintData's vtable (address
 * point 0x169bc50): the bridge atoms and the schema the path's solver
 * needs (400 bytes with the 32-byte header, eight solver results and
 * eight temporaries). */
// NONMATCHING: the counts' stores: the base merges +0 and +4 into one 8-byte
// store and keeps +8 and +0xc apart; this merges both pairs. Seven library
// functions end on such an unmerged pair (docs/NOTES.md, Rounds 29 to 32).
void hkpPointToPathConstraintData::FUN_0007a020(hkpConstraintData::ConstraintInfo &infoOut) const
{
    infoOut.atoms = &atoms;
    infoOut.sizeOfAllAtoms = sizeof(hkpBridgeAtoms);
    infoOut.maxSizeOfSchema = 0;
    infoOut.sizeOfSchemas = 400;
    infoOut.numSolverResults = 8;
    infoOut.numSolverElemTemps = 8;
}
