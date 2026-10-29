/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the support point for a direction, from the query's two
 * shapes. */
void SupportQuery000a8ef0::FUN_000a8ef0(const Vec4 &direction, SupportPoint000a8ef0 &pointOut) const
{
    support->getSupportPoint(shapeA, direction, shapeB, this, pointOut);
}
