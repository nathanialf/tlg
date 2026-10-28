/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpMaskedShape::FUN_000380b0(void *argument1, int argument2, int argument3,
                                  const ShapeKeyQuery000380b0 &argument4) const /* derived name */
{
    const hknpShape *shape = coreShape;
    const ShapeKeyQuery000380b0 query(argument4, mask);
    return shape->unknownVirtual21(argument1, argument2, argument3, query);
}
