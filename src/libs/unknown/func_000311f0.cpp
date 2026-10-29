/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorldObject380::FUN_000311f0(hknpWorldObject380MotionPair *out, const hknpMotion &motionA,
                                      const void *argument2, const hknpMotion &motionB)
{
    out->centerOfMassA = motionA.centerOfMass;
    out->centerOfMassB = motionB.centerOfMass;
    out->rotationA.setRotation(motionA.orientation);
    out->rotationB.setRotation(motionB.orientation);
}
