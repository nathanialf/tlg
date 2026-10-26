/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: this -= m, a column at a time. */
void hkMatrix3::FUN_0001afa0(const hkMatrix3 &m)
{
    col0 = _mm_sub_ps(col0, m.col0);
    col1 = _mm_sub_ps(col1, m.col1);
    col2 = _mm_sub_ps(col2, m.col2);
}
