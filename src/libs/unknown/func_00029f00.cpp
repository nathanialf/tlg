/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

#define SPLAT(v, i) _mm_shuffle_ps((v), (v), _MM_SHUFFLE(i, i, i, i))

/* NONMATCHING: 644 bytes against 702 (the frame 0x98 against 0xc8): every
 * output's expression tree is the base's (read from the base by a symbolic
 * walk of its dataflow, a81/sym in the round's scratchpad: Fc, Fcc, Fccc
 * packed with the constant two in +0xc0, Faab, Fbbc, Fcca, Fa and Fb), the
 * axis tests in the base's order (zero tested second); left, list-ilp's
 * order of the 120 vector operations and the spills that follow from it:
 * the base computes fa right after k1, the doubled and tripled terms
 * early and k2, k3, k4 last; written in that order the compile moves away
 * (Reassociate, under the unsafe math of D40, rebuilds the product chains
 * whatever their grouping). NOTES Round 81A. */
/* The face integrals from the projection integrals (Mirtich's
 * compFaceIntegrals): w from the face's first vertex, the normal's
 * components taken in the order A, B, C, k1 = 1/nC and its powers. */
void VolumeIntegrator00029b60::FUN_00029f00(const Vec4 *vertices, const Vec4 &normal)
{
    FUN_00029b60(vertices);
    Vec4 n = normal;
    const Vec4 d = _mm_dp_ps(n, vertices[0], 0x7f);
    const Vec4 w = _mm_sub_ps(_mm_setzero_ps(), d);
    if (axisC == 0) {
        n = _mm_shuffle_ps(n, n, _MM_SHUFFLE(3, 0, 2, 1));
    } else if (axisC == 1) {
        n = _mm_shuffle_ps(n, n, _MM_SHUFFLE(3, 1, 0, 2));
    }
    const Vec4 nA = SPLAT(n, 0);
    const Vec4 nB = SPLAT(n, 1);
    const Vec4 nC = SPLAT(n, 2);
    const Vec4 two = D_14b2060[4];
    const Vec4 three = D_14b2060[5];
    const Vec4 k1 = _mm_div_ps(D_14b2060[3], nC);
    const Vec4 k2 = _mm_mul_ps(k1, k1);
    const Vec4 k3 = _mm_mul_ps(k1, k2);
    const Vec4 k4 = _mm_mul_ps(k2, k2);
    const Vec4 negK2 = _mm_sub_ps(_mm_setzero_ps(), k2);
    const Vec4 nn = _mm_mul_ps(n, n);
    const Vec4 nA2 = SPLAT(nn, 0);
    const Vec4 nB2 = SPLAT(nn, 1);
    const Vec4 nAPa = _mm_mul_ps(nA, pa);
    const Vec4 nBPb = _mm_mul_ps(nB, pb);

    fa = _mm_mul_ps(k1, pa);
    fb = _mm_mul_ps(k1, pb);
    faab = _mm_mul_ps(k1, paab);

    const Vec4 sum1 = _mm_add_ps(SPLAT(nAPa, 0), SPLAT(nBPb, 0));
    const Vec4 twoNANB = _mm_mul_ps(nB, _mm_mul_ps(nA, two));
    const Vec4 inner2 =
        _mm_add_ps(_mm_mul_ps(nB, SPLAT(nBPb, 1)),
                   _mm_add_ps(_mm_mul_ps(nA, SPLAT(nAPa, 1)), _mm_mul_ps(twoNANB, pab)));
    const Vec4 sum2 =
        _mm_add_ps(inner2, _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, p1), _mm_mul_ps(two, sum1)), w));
    const Vec4 fcX = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, p1), sum1), negK2);
    const Vec4 fccY = _mm_mul_ps(k3, sum2);
    const Vec4 sum3 = _mm_add_ps(
        _mm_mul_ps(_mm_mul_ps(d, d), _mm_add_ps(_mm_mul_ps(w, p1), _mm_mul_ps(three, sum1))),
        _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(three, w), inner2),
            _mm_add_ps(
                _mm_mul_ps(nB2, SPLAT(nBPb, 2)),
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(nA2, SPLAT(nAPa, 2)),
                                      _mm_mul_ps(_mm_mul_ps(nB, _mm_mul_ps(nA2, three)), paab)),
                           _mm_mul_ps(_mm_mul_ps(nB2, _mm_mul_ps(nA, three)), pabb)))));
    const Vec4 fcccZ = _mm_xor_ps(_mm_mul_ps(k4, sum3), _mm_set1_ps(-0.0f));
    fc = _mm_movelh_ps(_mm_unpacklo_ps(fcX, fccY), _mm_unpacklo_ps(fcccZ, two));
    fbbc = _mm_mul_ps(
        _mm_add_ps(_mm_add_ps(SPLAT(nBPb, 2), _mm_mul_ps(nA, pabb)), _mm_mul_ps(SPLAT(pb, 1), w)),
        negK2);
    fcca = _mm_mul_ps(
        k3,
        _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(nA, SPLAT(nAPa, 2)), _mm_mul_ps(twoNANB, paab)),
                       _mm_mul_ps(nB2, pabb)),
            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(two, _mm_add_ps(SPLAT(nAPa, 1), _mm_mul_ps(nB, pab))),
                                  _mm_mul_ps(SPLAT(pa, 0), w)),
                       w)));
}
