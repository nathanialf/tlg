/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Eight zero bytes (rodata at 0x14bd980), the inverse inertia of a motion
 * of infinite mass. derived name. */
extern const hkHalf D_14bd980[4];

// NONMATCHING: greedy's assignment (206 instructions against 211, 817 of 836 bytes, the same blocks):
// the base copies the info into r15 and the world into r13 at entry and keeps them there, the world
// copied to r12 and r15 around the two signals' walks; here the world is in r15, the info left in
// rsi and spilled at the motion's choice, so the walks and the body's set-up take other registers.
u32 hknpWorld::FUN_0004e270(const hknpBodyCinfo &cinfo, int additionFlags, int mode)
{
    hknpBodyId bodyId;
    if (cinfo.reservedBodyId == 0x7fffffff) {
        if (bodyManager.firstFreeBodyId == 0x7fffffff) {
            signals.bodyBufferFullSignal.fire(this, &bodyManager);
        }
        bodyId.value = bodyManager.FUN_001607c0();
    } else {
        bodyId.value = cinfo.reservedBodyId;
    }

    /* The motion's type: none for a static body, else keyframed (1) when
     * its inverse inertia is zero, dynamic (2) otherwise. derived name. */
    int motionType;
    int motionId = cinfo.reservedMotionId;
    if (motionId == 0x7fffffff) {
        motionType = cinfo.motionType;
        motionId = 0;
        if (motionType != 0) {
            hknpMotionCinfo motionCinfo;
            FUN_0015b290(cinfo, motionCinfo);
            motionId = FUN_0004ce80(motionCinfo);
        }
    } else {
        const hknpMotion &motion = motionManager.motions[motionId];
        motionType = 0;
        if (motion.solverId != 0) {
            motionType = FUN_00018180(motion.inverseInertia, D_14bd980, 8) == 0 ? 1 : 2;
        }
    }

    hknpBody &body = bodyManager.bodies[bodyId.value];
    if (motionType != 0) {
        bodyManager.FUN_00160930(&body, bodyId.value, cinfo, 2);
        FUN_0004c170(bodyId.value, motionId, &cinfo.orientation);
    } else {
        bodyManager.FUN_00160930(&body, bodyId.value, cinfo, 0);
        body.nextAttachedBodyId = body.id;
        body.FUN_0003a920();
    }
    signals.bodyCreatedSignal.fire(this, cinfo, bodyId.value);
    if (additionFlags) {
        FUN_0004d650(&bodyId, 1, additionFlags, mode);
    }
    if (cinfo.shape->unknownVirtual8()) {
        shapeWatchers.FUN_00155ea0(&body);
    }
    return bodyId.value;
}
