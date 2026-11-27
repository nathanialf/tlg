/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_format01327490.h"

/* derived names: clamps four unsigned values to the widths in bits the
 * format gives for them (its bytes at +0x6 to +0x9), each limited to the
 * largest value of its width and masked to it. Its callers and the format's
 * other fields are not traced. */

/* The output and the input do not overlap (restrict): the base reads the
 * fourth value above the third store (`mov eax, [rsi+0xc]; mov [rdi+8], ecx`),
 * which the scheduler after register allocation does only for a load and a
 * store whose objects are both identified (ScheduleDAGInstrs.cpp,
 * getUnderlyingObjectsForInstr: an argument is one when it is noalias). */
void FUN_01327490(u32 *__restrict out, const u32 *__restrict in,
                  const Format01327490 *format) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        u32 largest = (1ull << format->bits[i]) - 1;
        u32 value = largest < in[i] ? largest : in[i];
        out[i] = value & largest;
    }
}
