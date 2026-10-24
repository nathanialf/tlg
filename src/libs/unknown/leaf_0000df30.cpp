/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: copies the 4x4 matrix at +0x10 of the object out, row by
 * row (a struct copy compiles to 256-bit moves; the base moves one row at a
 * time). Unknown owner. */
struct MatrixHolder {
    u8 unknown0[0x10];
    Mat4 matrix;
};

void FUN_0000df30(const MatrixHolder *self, Mat4 *out) /* derived name */
{
    out->r[0] = self->matrix.r[0];
    out->r[1] = self->matrix.r[1];
    out->r[2] = self->matrix.r[2];
    out->r[3] = self->matrix.r[3];
}
