/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: the transform is usable when x, y and z of its translation
 * are ordered numbers and its rotation is orthonormal. */
bool hkTransform::FUN_00010ce0() const
{
    if ((_mm_movemask_ps(_mm_cmpord_ps(translation, translation)) & 7) != 7) {
        return false;
    }
    return rotation.FUN_0000be80();
}
