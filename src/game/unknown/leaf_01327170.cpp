/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_format01327490.h"
#include "tlg_libc.h"

/* derived names: its pointer at 0x16c94c0 is in the table of conversions
 * at 0x16c94b0 (FUN_01327490's): packs four floats as unsigned values of the
 * widths in bits the format gives, each clamped to 0 and the largest value
 * of its width, rounded to nearest and masked to the width */
// NONMATCHING: the two pointers' registers swapped (the base holds the input in r12 and the
// format in r15, this build the other way) and with them the schedule, under the installed
// compiler and under cvtzero-01 (round 578E) alike; the operations, the calls to fmin and fmax
// and the frame the base's. Round 581E
void FUN_01327170(u32 *out, const float *in, const Format01327490 *format) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        u32 largest = (1ull << format->bits[i]) - 1;
        out[i] = (u32)floor(fmax(fmin(largest, in[i]), 0.0) + 0.5) & largest;
    }
}
