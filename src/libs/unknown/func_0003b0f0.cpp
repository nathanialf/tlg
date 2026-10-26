/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The wrapped shape's pointer is left as loaded; the decorator adds only its
 * vtable to hknpShape's finishing. */
hknpDecoratorShape::hknpDecoratorShape(hkFinishLoadedObjectFlag flag) : hknpShape(flag) {}
