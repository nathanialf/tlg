/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the data model, the jump table and every operation equal; two schedule classes
// left. The velocity join now loads as the base does (min, max, tau, value0): its exports' copies
// are made in the IR's order and the bottom-up list-ilp schedule reverses them (debug llc,
// -debug-only=pre-RA-sched: the CopyToReg of the first export gets the highest unit number and is
// placed first from the bottom), so the case assigns value0 first and the forces last. The
// position case still schedules the sign constant, the negated range and value0 ahead of the
// forces (the base: max, tau, the constant, min, -range, damping, value0); its assignment order
// does not move it (three orders compiled). With it the tail's phis take value0, min, max in
// xmm0 to xmm2 where the base has min, max, value0 (NOTES "Round 73B").
void FUN_0017d190(const hkpConstraintMotor *motor, const MotorInput0017d190 *input,
                  MotorOutput0017d190 *output)
{
    float minForce;
    float maxForce;
    float value10;
    float value14;
    float targetVelocity;
    float value0;
    switch (motor->type) {
    case hkpConstraintMotor::TYPE_POSITION: {
        const hkpPositionConstraintMotor *m =
            static_cast<const hkpPositionConstraintMotor *>(motor);
        const float error = input->unknown1c;
        const float proportional =
            error * m->proportionalRecoveryVelocity * input->stepInfo->unknownC;
        const float rest = error - proportional;
        const float limit = input->stepInfo->unknownC * m->constantRecoveryVelocity;
        const float target = input->unknown18;
        float delta = error;
        if (hkMath::fabs(rest) > limit) {
            delta = proportional + (rest > 0.0f ? limit : -limit);
        }
        maxForce = m->maxForce;
        minForce = -m->maxForce;
        value10 = m->tau;
        value14 = m->damping;
        value0 = input->unknown14;
        const float range = hkMath::fabs(error);
        targetVelocity =
            (target + hkMath::min2(hkMath::max2(delta, -range - value0), range - value0)) *
            input->stepInfo->unknown10;
        break;
    }
    case hkpConstraintMotor::TYPE_VELOCITY: {
        const hkpVelocityConstraintMotor *m =
            static_cast<const hkpVelocityConstraintMotor *>(motor);
        if (m->useVelocityTargetFromConstraintTargets) {
            targetVelocity = (input->unknown18 + input->unknown1c) * input->stepInfo->unknown10;
        } else {
            targetVelocity = m->velocityTarget;
        }
        value0 = input->unknown14;
        value14 = m->tau;
        value10 = m->tau;
        maxForce = m->maxForce;
        minForce = m->minForce;
        break;
    }
    case hkpConstraintMotor::TYPE_SPRING_DAMPER: {
        const hkpSpringDamperConstraintMotor *m =
            static_cast<const hkpSpringDamperConstraintMotor *>(motor);
        const float invMass = 1.0f / input->unknown0;
        const float dt = input->stepInfo->unknown0;
        value0 = input->unknown18 + input->unknown1c;
        targetVelocity = 0.0f;
        minForce = m->minForce;
        maxForce = m->maxForce;
        value14 = hkMath::clamp(invMass * (dt * m->springDamping), 0.0f, 1.0f);
        value10 = hkMath::clamp(invMass * (dt * dt * m->springConstant), 0.0f, 1.0f);
        break;
    }
    case hkpConstraintMotor::TYPE_CALLBACK: {
        const hkpCallbackConstraintMotor *m =
            static_cast<const hkpCallbackConstraintMotor *>(motor);
        m->callbackFunc(m, input, output);
        return;
    }
    default:
        return;
    }
    output->targetVelocity = targetVelocity;
    output->unknown0 = value0;
    output->maxForce = maxForce;
    output->minForce = minForce;
    output->unknown10 = value10;
    output->unknown14 = value14;
}
