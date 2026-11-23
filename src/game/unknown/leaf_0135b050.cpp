/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

Float4A FUN_00315a10(const Float4 &rotation, float x, float y, float z); /* derived name */

/* derived names: a point turned in place by the inverse of the rotation at
 * the first argument (its x, y and z negated into a temporary of the
 * call, w kept: the temporary below the result's slot, which the call
 * makes first), through FUN_00315a10 as FUN_0134b990 turns it, and
 * returned. Called and never inlined in the base: defined over its own
 * parameter types, leaf_00ff5c30.cpp's declaration is of another name. */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it, and 1 draft (round 513D:
 * cause not found; not its address range, its callers' count, its cost or its unit: a single
 * block, cost 85 under the link's threshold of 262 with its bonuses, and with it outside the
 * module every row holds) */
Float4A *FUN_0135b050(const Float4A *rotation, Float4A *point) /* derived name */
{
    *point = FUN_00315a10(Float4(-rotation->x, -rotation->y, -rotation->z, rotation->w), point->x,
                          point->y, point->z);
    return point;
}
