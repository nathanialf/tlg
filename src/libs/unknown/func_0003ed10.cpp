/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the instance's scale set, its w one, and the flags it
 * implies: scaled unless x, y and z are all one, the orientation flipped
 * when an odd number of them is negative, the surface kept unless the
 * mode is 0 (the game sets mode 0 at 0xea5b04 and 0xea6214). */
void hknpShapeInstance::FUN_0003ed10(const Vec4 &newScale, int scaleMode)
{
    int flags = getFlags() & ~(HAS_SCALE | FLIP_ORIENTATION | SCALE_SURFACE);
    const Vec4 one = D_14b2060[3];
    if (_mm_movemask_ps(_mm_cmpneq_ps(newScale, one)) & 7) {
        flags |= HAS_SCALE;
    }
    switch (_mm_movemask_ps(_mm_cmplt_ps(newScale, _mm_setzero_ps())) & 7) {
    case 1:
    case 2:
    case 4:
    case 7:
        flags |= FLIP_ORIENTATION;
        break;
    default:
        break;
    }
    scale.quad = _mm_blend_ps(newScale, one, 8);
    if (scaleMode == 0) {
        flags |= SCALE_SURFACE;
    }
    setFlags(flags);
}
