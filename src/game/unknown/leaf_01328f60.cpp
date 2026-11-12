/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the fourth entry of the function table at 0x16c5570 (the
 * second is FUN_01328ed0): converts four ints to floats, each less half its
 * range, the range's bit counts the bytes at +0x6 to +0x9 of its third
 * argument (the int plus the complement of the mask of one bit fewer). The
 * types are not traced. */
struct Format01328f60 { /* derived name */
    u8 unknown0[0x6];
    u8 bits[4]; /* +0x6 */
};

// NONMATCHING: the base shifts 1 in 64 bits and keeps dec; not; add (mov eax, 1; shl rax, cl; dec eax; not eax; add eax, [rsi]), the build folds the complement to -1 << n; the source form is not found
void FUN_01328f60(float *out, const int *in, const Format01328f60 *format) /* derived name */
{
    out[0] = static_cast<float>(in[0] + ~((1 << (format->bits[0] - 1)) - 1));
    out[1] = static_cast<float>(in[1] + ~((1 << (format->bits[1] - 1)) - 1));
    out[2] = static_cast<float>(in[2] + ~((1 << (format->bits[2] - 1)) - 1));
    out[3] = static_cast<float>(in[3] + ~((1 << (format->bits[3] - 1)) - 1));
}
