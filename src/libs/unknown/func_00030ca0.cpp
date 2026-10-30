/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 196 of 197. The info's flag is stored first because the
// info is declared before the arrays: its store then follows two lifetime
// starts in the selection DAG, not five, and the ILP scheduler's critical
// path test no longer sinks it below the table's loads (the arrays are in
// the large-array group, so their declaration after the info leaves the
// frame as the base's). Left: the scaled mass's operands, Reassociate's
// commute of the fmul by rank (3.3 Reassociate.cpp:1837-1852): the mass's
// extract ranks the rcp call plus four, the step's product the second load
// plus one, one below; the base's order needs one more unmovable
// instruction between the rcp call and the step's loads, or the loads in a
// later block when Reassociate runs (docs/NOTES.md, Round 59A).
int FUN_00030ca0(hknpWorldObject380Pair *pair, const hknpWorldObject380StepInfo *stepInfo,
                 const hknpWorldObject380Source *source, u32 flags, u16 valueB0,
                 const hknpBody *bodyA, float value0, float value1, float value2,
                 const hknpMotion *motionA, const hknpMaterial *materialA, const hknpBody *bodyB,
                 const hknpMotion *motionB, const hknpMaterial *materialB,
                 hknpWorldObject380Writer *writer) /* derived name */
{
    hknpWorldObject380Inertias inertias;
    hknpWorldObject380Info info;
    info.flag = false;
    Vec4 arrayA[4];
    Vec4 arrayB[4];
    hknpWorldObject380Bodies bodies;
    hknpCdBody cdBodyA;
    hknpCdBody cdBodyB;
    Vec4 header;

    for (int i = 0; i < 4; i++) {
        arrayA[i] = D_14b2060[2];
    }
    for (int i = 0; i < 4; i++) {
        arrayB[i] = D_14b2060[2];
    }
    header = _mm_setzero_ps();
    const void *pointer38 = source->pointer38;

    bodies.centerOfMassA = motionA->centerOfMass;
    bodies.centerOfMassB = motionB->centerOfMass;
    bodies.rotationA.setRotation(motionA->orientation);
    bodies.rotationB.setRotation(motionB->orientation);

    hkHalf half4;
    half4.setReal(value0);
    switch (pair->combineType) {
    case 0:
        bodies.halfA0.setReal(value1);
        bodies.byteA2 = u8(value2 * (1.0f / 255.0f));
        bodies.halfA4 = half4;
        bodies.halfA6.value = 0;
        bodies.halfA8.value = 0;
        bodies.flags = flags;
        bodies.valueB0 = valueB0;
        break;
    case 1:
        bodies.halfA0.value = 0;
        bodies.byteA2 = 0xff;
        bodies.halfA4.value = 0;
        bodies.halfA6.value = 0;
        bodies.halfA8.value = 0;
        bodies.flags = flags;
        bodies.valueB0 = valueB0;
        break;
    case 2:
        bodies.halfA0.value = 0;
        bodies.byteA2 = 0xff;
        bodies.halfA4 = half4;
        bodies.halfA6.value = 0;
        bodies.halfA8.value = 0;
        bodies.flags = flags;
        bodies.valueB0 = valueB0;
        break;
    case 3:
        bodies.halfA0.value = 0;
        bodies.byteA2 = 0xff;
        bodies.halfA4.value = 0;
        bodies.halfA6.value = 0;
        bodies.halfA8.value = 0;
        bodies.flags = 0;
        bodies.valueB0 = 0;
        break;
    }

    bodies.centerOfMassA = _mm_add_ps(bodies.centerOfMassA, pair->offsetA);
    bodies.centerOfMassB = _mm_add_ps(bodies.centerOfMassB, pair->offsetB);
    bodies.vector80 = _mm_set1_ps(100.0f);
    bodies.vector90 = _mm_set1_ps(-0.05f);
    bodies.pointerB8 = pointer38;

    inertias.inverseInertiaA = loadHalves(motionA->inverseInertia);
    inertias.inverseInertiaB = loadHalves(motionB->inverseInertia);
    const Vec4 sum = _mm_add_ps(inertias.inverseInertiaA, inertias.inverseInertiaB);
    const Vec4 inverseMass = _mm_shuffle_ps(sum, sum, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 mass =
        _mm_andnot_ps(_mm_cmpeq_ps(inverseMass, _mm_setzero_ps()), _mm_rcp_ps(inverseMass));
    reinterpret_cast<float *>(&arrayA[0])[0] =
        _mm_cvtss_f32(mass) * (stepInfo->valueC4 * stepInfo->value40);
    inertias.pointer20 = &header;
    inertias.pointer28 = arrayB;
    inertias.pointer30 = arrayB;
    inertias.pointer38 = arrayA;

    cdBodyA.body = bodyA;
    cdBodyA.motion = motionA;
    cdBodyA.material = materialA;
    cdBodyA.leafShape = bodyA->shape;
    cdBodyA.rootShape = 0;
    cdBodyA.shapeKey = 0xffffffff;

    cdBodyB.body = bodyB;
    cdBodyB.motion = motionB;
    cdBodyB.material = materialB;
    cdBodyB.leafShape = bodyB->shape;
    cdBodyB.rootShape = 0;
    cdBodyB.shapeKey = 0xffffffff;

    bodies.pointerC0 = source;
    return FUN_0002b6c0(const_cast<hknpWorldObject380StepInfo *>(stepInfo), pair, &bodies, &info,
                        &inertias, &cdBodyA, &cdBodyB, writer);
}
