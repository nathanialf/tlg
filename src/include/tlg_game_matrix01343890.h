/* src/include/tlg_game_matrix01343890.h: the 4x4 matrix FUN_01343890 and its
 * siblings build from a rotation and a position, read from their stores
 * (three rows of a rotation with a zero fourth lane, then the position as
 * the fourth row, copied with aligned moves). Every name here is derived. */
#ifndef TLG_GAME_MATRIX01343890_H
#define TLG_GAME_MATRIX01343890_H

#include "tlg_math.h"

struct Matrix01343890 { /* derived name */
    Float4A rows[4];
};

/* derived name: the rotation of the quaternion q (normalized by its squared
 * length) with the position as the fourth row (44 call sites). */
void FUN_01343890(Matrix01343890 *out, const Float4A &q, const Float4A &position);

#endif
