/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether three vectors, each given as three floats, wind the
 * same way about the second: the cross products b x a, b x c and a x c, true
 * when (b x a) . (b x c), (a x c) . (b x c) and (a x c) . (b x a) are all
 * positive, each tested before the next is formed. */
// NONMATCHING: the products' factor order: the base keeps ay*bz, bx*cz, bx*cy, az*by, ax*by
// with the first factor the lower argument and cz*by, cy*bz, cx*by with the higher, the build's
// Reassociate orders every two-factor product by the arguments' ranks (higher first)
bool FUN_0113f820(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy,
                  float cz) /* derived name */
{
    const float bcX = cz * by - cy * bz;
    const float bcY = cx * bz - bx * cz;
    const float bcZ = bx * cy - cx * by;
    const float baX = az * by - ay * bz;
    const float baY = ax * bz - az * bx;
    const float baZ = ay * bx - ax * by;
    if (baX * bcX + baY * bcY + baZ * bcZ <= 0.0f) {
        return false;
    }
    const float acX = ay * cz - az * cy;
    const float acY = az * cx - ax * cz;
    const float acZ = ax * cy - ay * cx;
    if (acX * bcX + acY * bcY + acZ * bcZ <= 0.0f) {
        return false;
    }
    return acX * baX + acY * baY + acZ * baZ > 0.0f;
}
