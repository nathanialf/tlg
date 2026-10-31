/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The directions of a 7 by 7 grid of coordinates from 0 to 1 in sixths,
 * room for all 49 taken first. */
hknpGlobals::hknpGlobals()
{
    directions.reserve(hkContainerHeapAllocator::get(), 7 * 7);
    hkVector4 coordinates;
    for (int i = 0; i < 7; i++) {
        lane(coordinates.quad, 0) = float(i) * (1.0f / 6.0f);
        for (int j = 0; j < 7; j++) {
            lane(coordinates.quad, 1) = float(j) * (1.0f / 6.0f);
            FUN_000c05b0(coordinates, directions.expandOne());
        }
    }
}
