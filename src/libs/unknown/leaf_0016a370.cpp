/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpBodyQuality's default constructor: nothing is initialized, so the
 * body is empty, and the linker's one copy of it is also the body behind 9
 * empty vtable slots in .data.rel.ro (from 0x16a55c0) and the collision
 * dispatcher's no-cache creator, which names it FUN_0016a370 (D15). */
hknpBodyQuality::hknpBodyQuality() {}
