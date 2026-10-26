/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: sets the ragdoll motors' target_bRca to the product of the
 * given rotation and transformA's rotation (called from the game at
 * 0xeb175d). */
void hkpRagdollConstraintData::FUN_0007df80(const hkMatrix3 &target)
{
    atoms.ragdollMotors.target_bRca.FUN_0001a9f0(target, atoms.transforms.transformA.rotation);
}
