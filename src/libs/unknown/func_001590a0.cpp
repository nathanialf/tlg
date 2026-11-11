/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpMotionCinfo::hknpMotionCinfo()
{
    motionPropertiesId = 0xffff;
    enableDeactivation = true;
    inverseMass = 1.0f;
    inverseInertiaLocal = D_14b2060[3];
    maxLinearAccelerationDistancePerStep = HK_REAL_HIGH;
    maxRotationPerStep = HK_REAL_HIGH;
    centerOfMassWorld = _mm_setzero_ps();
    orientation.vec = D_14b2060[32];
    angularVelocity = _mm_setzero_ps();
    linearVelocity = _mm_setzero_ps();
}

/* A shape's mass properties: the compressed ones it keeps under property
 * key 0xf100 unpacked, else those its slot 28 builds for the default
 * config. derived name. */
static inline void getShapeMassProperties(const hknpShape *shape, hkMassProperties &out)
{
    const hknpShapeMassProperties *shapeMass =
        shape->properties
            ? static_cast<const hknpShapeMassProperties *>(shape->properties->FUN_0001c550(0xf100))
            : HK_NULL;
    if (shapeMass) {
        shapeMass->compressedMassProperties.FUN_000261a0(out);
    } else {
        MassConfig00168340 config;
        hkDiagonalizedMassProperties diagonalized;
        shape->unknownVirtual28(&config, &diagonalized);
        diagonalized.FUN_00026490(out);
    }
}

/* The mass properties of several bodies combined in a frame: each body's
 * own placed by its transform relative to the frame. derived name. */
static void combineMassProperties(const hknpBodyCinfo *bodyCinfos, int numBodyCinfos,
                                  const hkTransform &frame, hkMassProperties &massPropertiesOut)
{
    hkArray<hkMassElement> elements;
    elements.setSize(numBodyCinfos);
    for (int i = 0; i < numBodyCinfos; i++) {
        const hknpBodyCinfo &body = bodyCinfos[i];
        getShapeMassProperties(body.shape, elements[i].properties);
        hkTransform bodyTransform;
        bodyTransform.rotation.FUN_0000bd30(body.orientation);
        bodyTransform.translation = body.position;
        elements[i].transform.FUN_00010d10(bodyTransform, frame);
    }
    FUN_000298a0(elements, massPropertiesOut);
}

// NONMATCHING: greedy's assignment, round 142C (164 of 192 by sequence, 967 bytes for 951, every
// instruction's shape and the frame layout the base's): the body count lives in r14 and the first
// body's orientation address in rbx, each copied into the loop (`mov r13d, r14d`, `mov r12, rbx`)
// where the base holds them in r13 and r12 from the start; inside the loop the base spills the
// down counter (-0x134) and keeps the body pointer, this spills the pointer (-0x138). Landed: the
// several bodies' combination a static helper of the file (its array's slot then precedes the
// frame's, -0xa0 as the base), the orientation copied as a vector so its address folds at the end.
void hknpMotionCinfo::FUN_00159130(const hknpBodyCinfo *bodyCinfos, int numBodyCinfos)
{
    hkTransform frame;
    frame.rotation.FUN_0000bd30(bodyCinfos[0].orientation);
    frame.translation = _mm_blend_ps(bodyCinfos[0].position, D_14b2060[2], 8);
    hkMassProperties massProperties;
    if (numBodyCinfos == 1) {
        getShapeMassProperties(bodyCinfos[0].shape, massProperties);
    } else {
        combineMassProperties(bodyCinfos, numBodyCinfos, frame, massProperties);
    }
    FUN_00010f50(centerOfMassWorld, frame, massProperties.centerOfMass);
    orientation.vec = bodyCinfos[0].orientation.vec;
    inverseMass = 0.0f;
    inverseInertiaLocal = _mm_setzero_ps();
    motionPropertiesId = 1;
    linearVelocity = bodyCinfos[0].linearVelocity;
    angularVelocity = bodyCinfos[0].angularVelocity;
}
