/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* NONMATCHING: equal but for the compiled atoms' pointer, which the base
 * loads and adds to (`mov rdi, [rax+0x2a0]; add rdi, rcx`, the form
 * instruction selection gives) and this compile folds (`add rdi,
 * [rax+0x2a0]`): the peephole optimizer's load fold after commuting the
 * add, refused in 3.3 when a DBG_VALUE is a second use of the load (the
 * round 31 `-g` question; docs/NOTES.md, Round 43). */
hkResult hkp6DofConstraintData::FUN_0017bb80(float factor)
{
    blueprints.ballSocket.inertiaStabilizationFactor = hkMath::clamp(factor, 0.0f, 1.0f);
    if (!isDirty) {
        /* The ball-socket atom's compiled copy (atom 7 of the blueprints),
         * or none yet: then the atoms are rebuilt. */
        const int offset = atomToCompiledAtomOffset[7];
        if (offset >= 0) {
            u8 *compiled = compiledAtoms.data;
            FUN_00017e70(compiled + offset, &blueprints.ballSocket, sizeof(blueprints.ballSocket));
        } else {
            isDirty = true;
        }
    }
    return HK_SUCCESS;
}
