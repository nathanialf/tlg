/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the post-finish function of hknpCompoundShape, registered as
 * the "hk.PostFinish" attribute (0x1692e80, 0x169ab90) of
 * hknpDynamicCompoundShape's and hknpStaticCompoundShape's classes: once a
 * loaded shape is finished, its AABB is recomputed. It sits in
 * hknpCompoundShape's reflection TU, before its slot 3 (FUN_000418b0). */
void FUN_000415f0(void *object) /* derived name */
{
    static_cast<hknpCompoundShape *>(object)->updateAabb();
}
