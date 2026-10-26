/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Empty the geometry: no triangles, no vertices. */
void hkGeometry::FUN_00093c70() /* derived name */
{
    triangles.clear();
    vertices.clear();
}
