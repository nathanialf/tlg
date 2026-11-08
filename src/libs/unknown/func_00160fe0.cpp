/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpBodyManager::FUN_00160fe0(u32 bodyId, hknpBodyCinfo &cinfoOut) const
{
    const hknpBody &body = bodies[bodyId];
    cinfoOut.shape = body.shape;
    cinfoOut.qualityId = body.qualityId;
    cinfoOut.materialId = body.materialId.value;
    cinfoOut.reservedMotionId = body.motionId;
    cinfoOut.collisionFilterInfo = body.collisionFilterInfo;
    cinfoOut.flags = body.flags & ~0xf;
    /* The look-ahead distance the body keeps in its translation's w. */
    const Vec4 translation = body.transform.translation;
    _mm_store_ss(&cinfoOut.collisionLookAheadDistance,
                 _mm_shuffle_ps(translation, translation, _MM_SHUFFLE(3, 3, 3, 3)));
    cinfoOut.position = body.transform.translation;
    cinfoOut.orientation.FUN_0001a1c0(body.transform.rotation);
    const int numNames = bodyNames.getSize();
    cinfoOut.name = bodyId < u32(numNames) ? bodyNames[bodyId].cString() : HK_NULL;
    cinfoOut.localFrame = HK_NULL;
    cinfoOut.mass =
        bodyId < u32(bodyEntries.getSize()) ? bodyEntries[bodyId].half.getReal() : -1.0f;
    cinfoOut.motionPropertiesId =
        bodyId < u32(bodyEntries.getSize()) ? bodyEntries[bodyId].value : u16(0xffff);
    if (const hknpMassDistribution *massDistribution = getMassDistribution(bodyId)) {
        hknpRefMassDistribution *copy = new hknpRefMassDistribution();
        cinfoOut.massDistribution.setAndDontIncrementRefCount(copy);
        copy->massDistribution = *massDistribution;
    }
    cinfoOut.linearVelocity = world->FUN_0005df00(bodyId);
    world->FUN_0005df30(bodyId, cinfoOut.angularVelocity);
}
