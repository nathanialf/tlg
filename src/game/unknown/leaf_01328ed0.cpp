/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the second entry of the function table at 0x16c5570:
 * converts four ints to floats as twice the int times the matching double of
 * the four at +0x28 of its third argument, less one. The types are not
 * traced. */
struct Scale01328ed0 { /* derived name */
    u8 unknown0[0x28];
    double unknown28[4];
};

void FUN_01328ed0(float *out, const int *in, const Scale01328ed0 *scale) /* derived name */
{
    double x = in[0] * 2.0 * scale->unknown28[0] - 1.0;
    double y = in[1] * 2.0 * scale->unknown28[1] - 1.0;
    double z = in[2] * 2.0 * scale->unknown28[2] - 1.0;
    double w = in[3] * 2.0 * scale->unknown28[3] - 1.0;
    out[0] = static_cast<float>(x);
    out[1] = static_cast<float>(y);
    out[2] = static_cast<float>(z);
    out[3] = static_cast<float>(w);
}
