/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_libc.h"

/* derived names: FUN_006543c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5811380(D_15cb5dd, false);
Name D_5811384(D_15cb5e6, false);

/* derived names: three angles in radians, about x, y and z */
struct Angles01360110 { /* derived name */
    float x;
    float y;
    float z;
};

/* derived name: a 4x4 transform, its rows four-lane vectors */
struct Matrix01360110 { /* derived name */

    /* derived name: a row's three values set, its w 0 */
    void setRow(int row, float x, float y, float z)
    {
        lane(rows[row], 0) = x;
        lane(rows[row], 1) = y;
        lane(rows[row], 2) = z;
        lane(rows[row], 3) = 0.0f;
    }

    Vec4 rows[4];
};

/* FUN_01360110 (ten callers, FUN_0064d060 the first): the rotation of three
 * angles, about x, then y, then z, written to a matrix whose last row is
 * this file's VECTOR_W (each sine and cosine through _FSin, in the order of
 * the angles). derived name */
// NONMATCHING: 56/81 at the base's 341 bytes, every register equal: the base computes row 0's two
// products and -sy before sy * sx and sy * cx (all five before the first store), the build the two
// shared products first (the order of the block's products under list-ilp; with them after row 0's
// stores the stores move up instead, 36/80)
void FUN_01360110(Matrix01360110 *matrix, const Angles01360110 *angles)
{
    const float sx = sin(angles->x);
    const float cx = cos(angles->x);
    const float sy = sin(angles->y);
    const float cy = cos(angles->y);
    const float sz = sin(angles->z);
    const float cz = cos(angles->z);
    const float sysx = sy * sx;
    const float sycx = sy * cx;
    matrix->setRow(0, cz * cy, sz * cy, -sy);
    matrix->setRow(1, cz * sysx - sz * cx, cz * cx + sz * sysx, cy * sx);
    matrix->setRow(2, cz * sycx + sz * sx, sz * sycx - cz * sx, cy * cx);
    matrix->rows[3] = VECTOR_W.v;
}
