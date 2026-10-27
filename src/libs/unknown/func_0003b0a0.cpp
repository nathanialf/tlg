/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpDecoratorShape::hknpDecoratorShape(const hknpShape *coreShape_)
    : hknpShape(coreShape_->dispatchType), coreShape(coreShape_)
{
}
