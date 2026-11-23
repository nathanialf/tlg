/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: the product of two rotations (x, y, z, then w), first then
 * second, written to its first argument (1,442 calls). The four lanes are
 * built in one Float4 before the store, each read once; under fast-math
 * Reassociate orders each lane's sum by the rank of its first read
 * (first.x, second.w, first.w, second.x, first.z, second.y, first.y,
 * second.z: the order lane x reads them), so the four terms that take the
 * second's z come last and the vectorizer packs them into one vector
 * product, an add and a subtract blended. The store is unaligned: the
 * product is a Float4, not a Float4A. */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 13 rowed callers where the base calls it, and 2 drafts (round 513D:
 * cause not found; not its address range, its callers' count, its cost or its unit: a single
 * block, cost 135 to 175 under the link's threshold of 393 with its bonuses, and with it outside
 * the module every row holds) */
void FUN_013439c0(Float4 *product, const Float4 *first, const Float4 *second) /* derived name */
{
    const Float4 &a = *first;
    const Float4 &b = *second;
    *product = Float4(a.x * b.w + a.w * b.x - a.z * b.y + a.y * b.z,
                      a.y * b.w + a.z * b.x + a.w * b.y - a.x * b.z,
                      a.z * b.w - a.y * b.x + a.x * b.y + a.w * b.z,
                      a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z);
}
