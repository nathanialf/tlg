/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: the same body as FUN_00462180 (leaf_00462180.cpp), a
 * separate function: where x lies between two bounds, 0 at `from` and 1 at `to`,
 * clamped; bounds given high to low are swapped and the result taken from 1;
 * equal bounds give 1. */
// NONMATCHING: block placement, the base lays out the `return 1` of equal bounds after the
// `jne` (fabsf(range) > 0 gives the base's single `jne`, an fcmp one); oeq gives that layout
// with `jp`
float FUN_00ad5980(float x, float from, float to) /* derived name */
{
    if (from > to)
        return 1.0f - FUN_00ad5980(x, to, from);
    float range = to - from;
    if (!(fabsf(range) > 0.0f))
        return 1.0f;
    float clamped = x < from ? from : (x < to ? x : to);
    return (clamped - from) / range;
}
