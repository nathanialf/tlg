/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMaskedShape::FUN_00038010(const void *argument1, const void *argument2,
                                   const void *argument3, const ShapeQuery00038010 &argument4,
                                   void *argument5) const /* derived name */
{
    ShapeQuery00038010 query(argument4);
    query.mask = mask;
    coreShape->unknownVirtual23(argument1, argument2, argument3, &query, argument5);
}
