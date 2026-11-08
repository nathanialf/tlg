/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The unit in the last place of a double (derived name): its exponent less
 * 52, nothing below the smallest. */
static inline double ulp(double value)
{
    union {
        double real;
        s64 bits;
    } in, out;

    in.real = value;
    out.bits = (in.bits & 0x7ff0000000000000ll) - (52ll << 52);
    return out.bits < 0 ? 0.0 : out.real;
}

static inline __m128d absolute(__m128d value)
{
    typedef unsigned long long Lanes __attribute__((vector_size(16)));
    const Lanes bits = reinterpret_cast<Lanes>(value);
    const Lanes one = {1, 1};
    return reinterpret_cast<__m128d>((bits + bits) >> one);
}

/* derived names: the point the three planes share, from the approximate
 * equations' determinants (x, y and z over w) when the error the estimate
 * carries (the quotient times the error of w over w, the quotient's ulp
 * over w and the ulp) is below one somewhere, else from the exact
 * determinants divided as integers. */
// NONMATCHING: size equal (595), the exact path equal; the estimate's block is list-ilp's
// order: the base divides y, then z, the w error and x, and selects the ulps z, y, x
// (CMOV_FR64's branches), the products ordered r * y, r * z, x * r by Reassociate's ranks;
// the order of these statements' definitions does not move the schedule (twelve orders
// compiled, a79/perm95.py), NOTES Round 79A.
void FUN_00095fc0(const hkcdPlanarPlane *planes, hkVector4d &intersectionOut)
{
    hkcdPlanarDeterminants determinants;
    FUN_00098800(planes[0].approxEquation, planes[1].approxEquation, planes[2].approxEquation,
                 determinants);
    const __m128d w = _mm_shuffle_pd(determinants.values.zw, determinants.values.zw, 3);
    const __m128d x =
        _mm_div_pd(_mm_shuffle_pd(determinants.values.xy, determinants.values.xy, 0), w);
    const __m128d y =
        _mm_div_pd(_mm_shuffle_pd(determinants.values.xy, determinants.values.xy, 3), w);
    const __m128d z =
        _mm_div_pd(_mm_shuffle_pd(determinants.values.zw, determinants.values.zw, 0), w);
    const __m128d wError =
        _mm_div_pd(_mm_shuffle_pd(determinants.errors.zw, determinants.errors.zw, 3), w);
    const __m128d ulpX = _mm_set1_pd(ulp(_mm_cvtsd_f64(x)));
    const __m128d ulpY = _mm_set1_pd(ulp(_mm_cvtsd_f64(y)));
    const __m128d ulpZ = _mm_set1_pd(ulp(_mm_cvtsd_f64(z)));
    const __m128d errorX = _mm_add_pd(absolute(_mm_mul_pd(x, wError)),
                                      _mm_add_pd(absolute(_mm_div_pd(ulpX, w)), ulpX));
    const __m128d errorY = _mm_add_pd(absolute(_mm_mul_pd(y, wError)),
                                      _mm_add_pd(absolute(_mm_div_pd(ulpY, w)), ulpY));
    const __m128d errorZ = _mm_add_pd(absolute(_mm_mul_pd(z, wError)),
                                      _mm_add_pd(absolute(_mm_div_pd(ulpZ, w)), ulpZ));
    const __m128d one = _mm_set1_pd(1.0);
    const int below = _mm_movemask_pd(_mm_cmplt_pd(_mm_unpacklo_pd(errorX, errorY), one)) |
                      _mm_movemask_pd(_mm_cmplt_pd(_mm_unpacklo_pd(errorZ, errorZ), one));
    if (below) {
        intersectionOut.xy = _mm_unpacklo_pd(x, y);
        intersectionOut.zw = _mm_unpacklo_pd(z, z);
        return;
    }
    hkSimdInt256 exactX;
    hkSimdInt256 exactY;
    hkSimdInt256 exactZ;
    hkSimdInt256 exactW;
    FUN_0009cb00(planes, exactX, exactY, exactZ, exactW);
    const int ix = FUN_00097810(exactX, exactW);
    const int iy = FUN_00097810(exactY, exactW);
    const __m128d xy = _mm_unpacklo_pd(_mm_set_sd(double(ix)), _mm_set_sd(double(iy)));
    const int iz = FUN_00097810(exactZ, exactW);
    intersectionOut.xy = xy;
    intersectionOut.zw = _mm_set1_pd(double(iz));
}
