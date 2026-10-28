/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the query's filter info against the body's.
 * NONMATCHING: the base extracts idB and dontCollideA with `bextr` (control
 * 0x505 and 0x50a); this compiles to `shr; and`. LLVM 3.3 selects BEXTR only
 * from its intrinsic; the combine that forms it from `(x >> c) & mask`
 * (X86ISelLowering PerformAndCombine, "Create BEXTR instructions") is in the
 * later releases (3.6.2:24407) and 47 library functions hold a `bextr`
 * (docs/NOTES.md, Round 42). */
bool hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516::FUN_0003a290(
    int queryType, const hknpQueryFilterData &filterData, const hknpBody &body) const
{
    return isCollisionEnabled(filterData.collisionFilterInfo, body.collisionFilterInfo) != 0;
}
