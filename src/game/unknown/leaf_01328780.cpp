/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a pixel format's description: the bit width of each of
 * its four channels at +0x6 */
struct Format01328780 { /* derived name */
    u8 unknown0[0x6];
    u8 bits[4]; /* +0x6 */
};

/* derived name: extends the sign of each of four channel values from the
 * channel's width in the format to 32 bits (no direct caller) */
// NONMATCHING: 252 bytes as the base, the order only: the base loads the
// next channel's width before it stores the channel (`movzx r8d, [rdx+7];
// mov [rdi], r9d`), the build after; in the IR the store comes first (the
// width a char load that may alias the store), so the base's IR had the
// width's load above it
void FUN_01328780(u32 *out, const u32 *in, const Format01328780 *format) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        const unsigned bits = format->bits[i];
        u32 value = in[i];
        if (value & ~u32((1ull << (bits - 1)) - 1))
            value |= ~u32((1ull << bits) - 1);
        out[i] = value;
    }
}
