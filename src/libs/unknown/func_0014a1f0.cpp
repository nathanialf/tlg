/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: empties the box: its minimum is the largest value and its maximum the most negative, so that any point extends it. */
void hkAabb::FUN_0014a1f0()
{
    Vec4 largest = D_14b2060[33];
    min = largest;
    max = _mm_xor_ps(largest, _mm_set1_ps(-0.0f));
}
