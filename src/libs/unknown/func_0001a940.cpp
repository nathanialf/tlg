/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

bool hkMatrix3::FUN_0001a940() const
{
    const int ordered = _mm_movemask_ps(_mm_cmpord_ps(col0, col0)) &
                        _mm_movemask_ps(_mm_cmpord_ps(col1, col1)) &
                        _mm_movemask_ps(_mm_cmpord_ps(col2, col2));
    return (ordered & 7) == 7;
}
