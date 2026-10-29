/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpCharacterRigidBodyCinfo::hknpCharacterRigidBodyCinfo()
{
    mass = 75.0f;
    maxForce = 1000.0f;
    dynamicFriction = 0.0f;
    staticFriction = 0.0f;
    weldingTolerance = 0.1f;
    maxSlope = HK_REAL_PI / 3.0f;
    up = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
    maxSpeedForSimplexSolver = 10.0f;
    collisionFilterInfo = 0;
    position = _mm_setzero_ps();
    orientation.vec = D_14b2060[32];
    supportDistance = 0.1f;
    hardSupportDistance = 0.0f;
    world = 0;
    shape = 0;
    reservedBodyId = hknpBodyId(0x7fffffff);
    additionMode = 2;
    activationMode = 0;
}
