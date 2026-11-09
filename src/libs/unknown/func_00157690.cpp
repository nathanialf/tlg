/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: one operand order, Reassociate's rank tie (3.3 Reassociate.cpp:1837-1852): the second
// product's first column takes its z term as `vmulps z, T.c2` in the base and `T.c2, z` here; its
// operands tie at rank 24 (the product's third column as an expression, the reloaded first column of
// offsetCross broadcast), so the source order stays. The base has z below T.c2: one fewer movable load
// between the first product's inertia loads and the reload. 912 bytes as the base, 1 line apart.
void hknpMotion::FUN_00157690(const Vec4 &position, hkMatrix3 &matrixOut) const
{
    const Vec4 inverseInertiaAndMass = loadHalves(inverseInertia);
    const Vec4 offset = _mm_sub_ps(position, centerOfMass);
    hkMatrix3 offsetCross;
    offsetCross.FUN_0001aca0(offset);

    hkMatrix3 inverseInertiaWorld;
    getInverseInertiaWorld(inverseInertiaWorld);

    float inverseMass = _mm_cvtss_f32(broadcast<3>(inverseInertiaAndMass));
    if (inverseMass == 0.0f) {
        inverseMass = 1.0f;
    }
    hkMatrix3 massMatrix;
    massMatrix.setDiagonal(inverseMass, inverseMass, inverseMass);
    hkMatrix3 crossProduct;
    crossProduct.setMulInPlace(offsetCross, inverseInertiaWorld);
    crossProduct.setMulInPlace(crossProduct, offsetCross);
    massMatrix.FUN_0001afa0(crossProduct);
    matrixOut.setInverseSymmetric(massMatrix);
}
