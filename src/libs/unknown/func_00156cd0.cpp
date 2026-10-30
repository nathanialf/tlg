/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the IR's operand orders are the base's; the register allocation differs (the
// base keeps the difference in xmm9 and the half in xmm4) and the base stores in each path
// (post-RA tail duplication over an uncoalesced phi), where this compile coalesces the stored
// value with the difference and stores once (NOTES Round 61B). Round 62B: the base's two
// stores are two stores in the IR, not a tail-duplicated phi (post-RA tail duplication keeps
// the phi's copy, MachineCopyPropagation forwards nothing); InstCombine's
// SimplifyStoreAtEndOfBlock (InstCombineLoadStoreAlloca.cpp) merges them unless the two
// stores differ in pointer value, type or alignment, or a path's store is not its last
// instruction.
void FUN_00156cd0(const Vec4 &from, const Vec4 &to, float speed, const Vec4 &velocity,
                  Vec4 &out) /* derived name */
{
    const Vec4 difference = _mm_sub_ps(to, from);
    const Vec4 distance = length3(difference);
    if (_mm_ucomigt_ss(distance, D_14b2060[35])) {
        const Vec4 speed4 = _mm_set1_ps(speed);
        const Vec4 scale =
            _mm_xor_ps(_mm_mul_ps(_mm_mul_ps(distance, _mm_rcp_ps(speed4)), D_14b2060[18]),
                       _mm_set1_ps(-0.0f));
        Vec4 correction = _mm_mul_ps(scale, velocity);
        const Vec4 correctionLength = length3(correction);
        if (_mm_ucomigt_ss(correctionLength, speed4)) {
            correction = _mm_mul_ps(correction, _mm_mul_ps(speed4, _mm_rcp_ps(correctionLength)));
        }
        out = _mm_add_ps(correction,
                         _mm_mul_ps(difference, _mm_mul_ps(speed4, _mm_rcp_ps(distance))));
    } else {
        out = difference;
    }
}
