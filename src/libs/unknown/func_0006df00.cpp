/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The vehicle data's destructor: its two arrays given back, the last
 * first. */
hknpVehicleData::~hknpVehicleData() {}

void hknpVehicleData::FUN_0006e0a0(
    const hkArray<hknpVehicleSuspension::SuspensionWheelParameters> &suspensionWheelParams,
    const hkTransform &chassisTransform, const hknpMotion &chassisMotion)
{
    alreadyInitialised = true;

    int numAxles = 0;
    for (int i = 0; i < numWheels; i++) {
        if (wheelParams[i].axle >= numAxles) {
            numAxles = wheelParams[i].axle + 1;
        }
    }
    if (numAxles > numWheelsPerAxle.getSize()) {
        numWheelsPerAxle.setSize(numAxles);
    }
    for (int i = 0; i < numWheelsPerAxle.getSize(); i++) {
        numWheelsPerAxle[i] = 0;
    }
    for (int i = 0; i < numWheels; i++) {
        numWheelsPerAxle[wheelParams[i].axle]++;
    }

    {
        Vec4 diagonal = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(hkMath::quadFabs(chassisOrientation.col0),
                                  _mm_set1_ps(torqueYawFactor / chassisUnitInertiaYaw)),
                       _mm_mul_ps(hkMath::quadFabs(chassisOrientation.col1),
                                  _mm_set1_ps(torqueRollFactor / chassisUnitInertiaRoll))),
            _mm_mul_ps(hkMath::quadFabs(chassisOrientation.col2),
                       _mm_set1_ps(torquePitchFactor / chassisUnitInertiaPitch)));
        diagonal[3] = 1.0f;
        const Vec4 inverseInertia = loadHalves(chassisMotion.inverseInertia);
        const Vec4 inverseMass = _mm_castsi128_ps(
            _mm_shuffle_epi32(_mm_castps_si128(inverseInertia), _MM_SHUFFLE(3, 3, 3, 3)));
        chassisFrictionInertiaInvDiag = _mm_mul_ps(diagonal, inverseMass);
    }

    hkpVehicleFrictionDescription::Cinfo cinfo;
    FUN_00010f90(cinfo.chassisCenterOfMass, chassisTransform, chassisMotion.centerOfMass);
    {
        const Vec4 diagonal = chassisFrictionInertiaInvDiag;
        hkMatrix3 scaled;
        scaled.col0 = _mm_mul_ps(_mm_shuffle_ps(diagonal, diagonal, _MM_SHUFFLE(0, 0, 0, 0)),
                                 chassisTransform.rotation.col0);
        scaled.col1 = _mm_mul_ps(_mm_shuffle_ps(diagonal, diagonal, _MM_SHUFFLE(1, 1, 1, 1)),
                                 chassisTransform.rotation.col1);
        scaled.col2 = _mm_mul_ps(_mm_shuffle_ps(diagonal, diagonal, _MM_SHUFFLE(2, 2, 2, 2)),
                                 chassisTransform.rotation.col2);
        cinfo.chassisFrictionInertiaInv.FUN_0001abb0(scaled, chassisTransform.rotation);
    }
    const Vec4 inverseInertia = loadHalves(chassisMotion.inverseInertia);
    cinfo.chassisMassInv = _mm_cvtss_f32(_mm_shuffle_ps(inverseInertia, inverseInertia, 3));
    cinfo.direction50 = hkMath::quadFabs(chassisOrientation.col0);
    cinfo.direction40 = hkMath::quadFabs(chassisOrientation.col1);
    cinfo.direction30 = hkMath::quadFabs(chassisOrientation.col2);
    cinfo.frictionEqualizer = frictionEqualizer;
    for (int axle = 0; axle < 2; axle++) {
        cinfo.wheelMassRadiusSum[axle] = 0.0f;
    }
    for (int i = 0; i < numWheels; i++) {
        const hknpVehicleDataWheelComponentParams &wheel = wheelParams[i];
        const hknpVehicleSuspension::SuspensionWheelParameters &suspension =
            suspensionWheelParams[i];
        const int axle = wheel.axle;
        cinfo.wheelRadius[axle] = wheel.radius;
        cinfo.wheelPosition[axle] = _mm_add_ps(
            _mm_mul_ps(_mm_set1_ps(suspension.length), suspension.directionChassisSpace.quad),
            suspension.hardpointChassisSpace.quad);
        cinfo.wheelMassRadiusSum[axle] += wheel.radius * wheel.mass;
    }
    FUN_00083ab0(cinfo, frictionDescription);
}
