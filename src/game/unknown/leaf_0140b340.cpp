/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: FUN_01401f60's shape (leaf_01401f60.cpp) over FUN_0140c010,
 * which computes the vector from the object at 0x5ad1770 instead of an object
 * argument (the same FUN_00f541c0 call; the result written with an aligned
 * move, its first argument returned): copies into out the vector read back
 * through the returned reference, the second argument passed through. */
const Float4 &FUN_0140c010(Float4A &result, const Float4 &value); /* derived name */

void FUN_0140b340(Float4 &out, const Float4 &value) /* derived name */
{
    Float4A result;
    out = FUN_0140c010(result, value);
}
