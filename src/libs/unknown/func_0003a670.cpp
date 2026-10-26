/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the body keeps its center of mass, in its own space, in the
 * w lanes of its rotation's columns. */
void hknpBody::FUN_0003a670(const Vec4 &centerOfMassLocal)
{
    lane(transform.rotation.col0, 3) = lane(centerOfMassLocal, 0);
    lane(transform.rotation.col1, 3) = lane(centerOfMassLocal, 1);
    lane(transform.rotation.col2, 3) = lane(centerOfMassLocal, 2);
}
