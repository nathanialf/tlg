/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpMaskedShape::FUN_00038130(const ShapeQuery00038130 &argument1,
                                  void *argument2) const /* derived name */
{
    ShapeQuery00038130 query = argument1;
    query.mask = mask;
    return coreShape->unknownVirtual29(&query, argument2);
}
