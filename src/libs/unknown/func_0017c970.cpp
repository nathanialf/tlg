/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkp6DofConstraintData::FUN_0017c970(const hkpRagdollMotorConstraintAtom &atom,
                                         AtomIndex atomIndex)
{
    const int offset = compiledAtoms.getSize();
    u8 *compiled = compiledAtoms.expandBy(int(sizeof(hkpRagdollMotorConstraintAtom)));
    if (atomIndex != NUM_ATOMS) {
        atomToCompiledAtomOffset[atomIndex] = offset;
    }
    hkString::memCpy16(compiled, &atom, sizeof(hkpRagdollMotorConstraintAtom) / 16);
    for (int i = 0; i < 6; i++) {
        resultToRuntime[4 + i] = numRuntimeElements++;
    }
}
