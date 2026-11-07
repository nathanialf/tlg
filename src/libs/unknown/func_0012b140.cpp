/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 487 bytes against 505; the loops are the base's do-whiles
// entered without guards and the keys built from the query's path in place.
// Left: the triangle loop's latch (the base tests the old count, `test esi,
// esi; jle`, and increments at the next iteration's top, 0x12b210; here
// `inc; cmp 2; jl`), the start key's triangle bit kept as `and 1` of the
// shifted key (here folded into `bt` on the key) with its increment not
// folded to one, and the key's mask loaded after the shift count
// (docs/NOTES.md, Round 75B).
int hknpHeightFieldShape::FUN_0012b140(void *keysOut, int maxNumKeys, int key,
                                       const ShapeKeyQuery000380b0 &query) const
{
    /* Where to start: the first triangle, or the one after the key's. */
    int x = 0;
    int z = 0;
    int triangle = 0;
    if (key != -1) {
        const u32 subKey = u32(key) >> (32 - numShapeKeyBits);
        x = (subKey >> 1) & ((1 << numBitsX) - 1);
        z = subKey >> (numBitsX + 1);
        triangle = subKey & 1;
        if (triangle == 1) {
            triangle = 0;
            if (x < intSizeX) {
                x++;
            } else {
                x = 0;
                if (z < intSizeZ) {
                    z++;
                } else {
                    return 0;
                }
            }
        } else {
            triangle++;
        }
    }

    u32 *keys = static_cast<u32 *>(keysOut);
    int numKeys = 0;
    do {
        do {
            do {
                const int subKey = (z << (numBitsX + 1)) + 2 * x + triangle;
                if (query.mask &&
                    !query.mask->FUN_000381f0(((subKey + 1) << (32 - numShapeKeyBits)) - 1)) {
                    continue;
                }
                *keys++ = query.path.makeKey(subKey, numShapeKeyBits);
                numKeys++;
                if (numKeys == maxNumKeys) {
                    return maxNumKeys;
                }
            } while (++triangle <= 1);
            triangle = 0;
        } while (++x <= intSizeX);
        x = 0;
    } while (++z <= intSizeZ);
    return numKeys;
}
