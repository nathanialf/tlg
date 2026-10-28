/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_lib_unknown.h"

/* derived name: every flagged point moved by the offset. */
void FlaggedPoints00060c70::FUN_00061280(const Vec4 &offset)
{
    for (int i = 0; i < numCells; i++) {
        if (flags[i]) {
            points[i] = _mm_add_ps(points[i], offset);
        }
    }
}
