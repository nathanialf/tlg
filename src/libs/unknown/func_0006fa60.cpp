/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 24 of hknpShape's vtable (address point 0x169ad30),
 * kept by hknpCompositeShape and hknpCompoundShape: the query of a shape
 * that has no special form of it, the generic one with the shape passed
 * third. */
void hknpShape::unknownVirtual24(const void *argument1, const void *argument2,
                                 const void *argument3, const void *argument4,
                                 void *argument5) const /* derived name */
{
    FUN_00169e50(argument1, argument2, this, argument3, argument4, argument5);
}
