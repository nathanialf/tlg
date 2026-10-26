/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: makes the box the whole space: its maximum is the largest value and its minimum the most negative. */
void hkAabb::FUN_0014a220()
{
    Vec4 largest = D_14b2060[33];
    max = largest;
    min = _mm_xor_ps(largest, _mm_set1_ps(-0.0f));
}
