/* src/libs/havok/Physics/Physics/Dynamics/World/hknpWorld.cpp:
 * the file its assert names (config/homes.base.txt, FUN_0004d0a0). */
#include "tlg_hk_reflect.h"

/* derived name: sets the world's gravity, the vector at +0x630 (called at
 * 0x16eff1 and by the game at 0xe99dd1). */
void hknpWorld::FUN_0004bcb0(const Vec4 &newGravity) /* derived name */
{
    gravity = newGravity;
}

/* derived name: sets the world's collision filter, held by the object at
 * +0x1b8 (the world's own constructor does the same at 0x4a1a7; the game
 * calls this at 0xea98cc). FUN_0004bcc0 sits between the constructor
 * FUN_00048b20 and the homed FUN_0004d0a0, all three on the same object. */
void hknpWorld::FUN_0004bcc0(hknpCollisionFilter *filter) /* derived name */
{
    modifierManager->FUN_000667b0(filter);
}

/* derived name: the signal of a world event type for one body, from the
 * event dispatcher at +0x6c8. */
hknpEventSignal *hknpWorld::FUN_0004fbd0(int eventType, int bodyId) /* derived name */
{
    return eventDispatcher->FUN_0006bdf0(hknpEventType::Enum(eventType), bodyId);
}

/* derived name: the signal of a world event type, from the event dispatcher
 * at +0x6c8. */
hknpEventSignal *hknpWorld::FUN_0004fbe0(int eventType) /* derived name */
{
    return eventDispatcher->FUN_0006bf60(hknpEventType::Enum(eventType));
}

/* derived name: the pointer at +0x10 of the world's object at +0x1d0
 * (called at 0x177435). */
void *hknpWorld::FUN_00051610() const /* derived name */
{
    return object1d0->elements;
}

// NONMATCHING: list-ilp order (202 of 212 instructions, 857 bytes as the base): the constraints'
// pointer is loaded after the created signal's head is tagged, just before the head's store, where the
// base loads it after the signal's address; after the walk the index's shift comes after the head's
// untagging, where the base shifts first. The bottom-up ILP pick ties to BURRSort's closestSucc (the
// load feeds the store's token factor); moving the load after the store in the IR (a85/t2.ll) puts
// it after the store, so the base's order is not that.
u32 hknpWorld::FUN_0004d0a0(const hknpConstraintCinfo &cinfo, hkBool32 keepInactive)
{
    if (cinfo.constraintData->unknownVirtual5() == 3) {
        HK_WARN(0xa32e5834, HK_NP_WORLD_CPP, 1318,
                "Attempted to create an unsupported constraint type. Skipping creation of the "
                "constraint.");
        return 0x7fffffff;
    }
    if (cinfo.bodyA == cinfo.bodyB) {
        HK_WARN(0x4c873b15, HK_NP_WORLD_CPP, 1323,
                "Attempted to constrain a body to itself. Skipping creation of the constraint.");
        return 0x7fffffff;
    }
    if (constraintManager.firstFreeConstraintId == 0x7fffffff) {
        signals.constraintBufferFullSignal.fire(this, &constraintManager);
    }
    const u32 constraintId = constraintManager.FUN_0016db90();
    constraintManager.FUN_0016dc90(constraintId, cinfo);
    const hknpConstraint &constraint = constraintManager.constraints[constraintId];
    signals.constraintCreatedSignal.fire(this, cinfo, constraintId);
    if (!(constraint.flags & 4)) {
        FUN_0004d400(&constraint, keepInactive);
        signals.constraintAddedSignal.fire(this, constraintId);
    }
    return constraintId;
}

/* derived name: a body turned to an orientation (0x5d330; the body manager's 0x16edc5 and the game
 * call it): nothing when the rotation is within epsilon of the body's, else the rotation taken; about
 * the centre of mass (pivot 1) the translation moved so the motion's centre of mass stays where it
 * is; then the transform's update, the static body moved signal for a body without a motion and the
 * body changed signal for any. */
void hknpWorld::FUN_0005d330(int bodyId, const hkQuaternion &orientation, int pivot,
                             int activation) /* derived name */
{
    hknpBody &body = bodyManager.bodies[bodyId];
    hkMatrix3 rotation;
    rotation.FUN_0000bd30(orientation);
    hkTransform transform = body.transform;
    const Vec4 epsilon = D_14b2060[35];
    if (FUN_0001add0(transform.rotation, rotation, epsilon)) {
        return;
    }

    transform.rotation = rotation;
    if (pivot == 1) {
        const hknpMotion &motion = motionManager.motions[body.motionId];
        const hkMatrix3 &bodyRotation = body.transform.rotation;
        const Vec4 centerOfMassLocal = setFromScalars(
            broadcast<3>(bodyRotation.getColumn(0)), broadcast<3>(bodyRotation.getColumn(1)),
            broadcast<3>(bodyRotation.getColumn(2)), broadcast<3>(bodyRotation.getColumn(2)));
        Vec4 centerOfMass;
        FUN_00010f50(centerOfMass, transform, centerOfMassLocal);
        transform.translation =
            _mm_add_ps(_mm_sub_ps(motion.centerOfMass, centerOfMass), transform.translation);
    }
    body.setTransformKeepingW(transform);
    FUN_0005c900(bodyId, &orientation, pivot, activation);

    if (body.motionId == 0) {
        signals.staticBodyMovedSignal.fire(this, bodyId);
    }
    signals.bodyChangedSignal.fire(this, bodyId);
}
