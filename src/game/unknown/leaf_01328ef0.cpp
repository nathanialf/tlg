/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a format of four components whose widths in bits are the
 * bytes at +0x6 to +0x9 */
struct Format01328ef0 { /* derived name */
    u8 unknown0[0x6];
    u8 bits[4]; /* +0x6 */
};

/* derived name: four unsigned values made signed by removing the half of
 * each component's range */
// NONMATCHING: instruction order only (9/33, same size): the base loads the
// next width before the store of the previous component (the byte load not
// ordered after the int store), the build after it.
void FUN_01328ef0(int *out, const int *in, const Format01328ef0 *format) /* derived name */
{
    for (int i = 0; i < 4; ++i)
        out[i] = in[i] + ~int((1ull << (format->bits[i] - 1)) - 1);
}
