/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clamps four unsigned values to the widths in bits the
 * format gives for them (its bytes at +0x6 to +0x9), each limited to the
 * largest value of its width and masked to it. Its callers and the format's
 * other fields are not traced. */
struct Format01327490 { /* derived name */
    u8 unknown0[6];
    u8 bits[4]; /* +0x6 */
};

// NONMATCHING: the base loads the fourth value (`mov eax, [rsi+0xc]`) before the third store, the
// build after it (34 of 37; `__restrict` on the output vectorizes the loop instead)
void FUN_01327490(u32 *out, const u32 *in, const Format01327490 *format) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        u32 largest = (1ull << format->bits[i]) - 1;
        u32 value = largest < in[i] ? largest : in[i];
        out[i] = value & largest;
    }
}
