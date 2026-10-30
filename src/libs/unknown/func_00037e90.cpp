/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMaskedShape::FUN_00037e90(const void *argument1, const void *argument2,
                                   const void *argument3, const void *argument4,
                                   const ShapeQuery00038010 &argument5, const void *argument6,
                                   void *argument7) const /* derived name */
{
    ShapeQuery00038010 query(argument5);
    query.mask = mask;
    coreShape->unknownVirtual25(argument1, argument2, argument3, argument4, &query, argument6,
                                argument7);
}
