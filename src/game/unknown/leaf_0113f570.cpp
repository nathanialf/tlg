/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_011c9730's walk (leaf_011c9730.cpp) over an array of
 * values toward an array of targets, each value by the same rate from the
 * eleven-entry table D_15251c0 (called by FUN_01114f30 and FUN_01124b60) */
extern const float D_15251c0[11]; /* derived: the rates by speed */

// The base's steps loop is split on the count being 0 by the unit pipeline's
// LoopUnswitch (tools/patches/llvm-3.7.1-unswitch-01-whole-invariant-branch.patch).
// The steps are counted down by a for loop: its latch (`cmp r9d, 1; jg`) is
// the decrement's own block, laid out before the rows' loop; written as
// `while (whole-- > 0)` the latch is the rows' loop's exit, laid out just
// before the next step's entry, and its branch is inverted at selection
// (`cmp r9d, 2; jge`).
void FUN_0113f570(Array05943280<float> *values, const Array05943280<float> *targets, float speed,
                  float step) /* derived name */
{
    const unsigned count = values->size();
    speed = speed < 0.0f ? 0.0f : (speed < 10.0f ? speed : 10.0f);
    unsigned index = (unsigned)speed;
    if (index == 10)
        index = 9;
    float part = speed - (float)index;
    float rate = (1.0f - part) * D_15251c0[index] + part * D_15251c0[index + 1];
    float frames = step * 59.999996f;
    int whole = (int)frames;
    float fraction = frames - (float)whole;
    for (; whole > 0; --whole)
        for (unsigned i = 0; i < count; ++i)
            values->at(i) = (targets->at(i) - values->at(i)) * rate + values->at(i);
    for (unsigned i = 0; i < count; ++i)
        values->at(i) = rate * fraction * (targets->at(i) - values->at(i)) + values->at(i);
}
