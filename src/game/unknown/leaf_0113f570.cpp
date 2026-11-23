/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_011c9730's walk (leaf_011c9730.cpp) over an array of
 * values toward an array of targets, each value by the same rate from the
 * eleven-entry table D_15251c0 (called by FUN_01114f30 and FUN_01124b60) */
extern const float D_15251c0[11]; /* derived: the rates by speed */

// NONMATCHING: the count's test only: the base tests it once before the
// whole steps' loop (`test eax, eax; je` to the return, after `jle`), the
// build at the head of each step (the inner loop's guard inside the outer
// loop); every other instruction is the base's
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
    while (whole-- > 0)
        for (unsigned i = 0; i < count; ++i)
            values->at(i) = (targets->at(i) - values->at(i)) * rate + values->at(i);
    for (unsigned i = 0; i < count; ++i)
        values->at(i) = rate * fraction * (targets->at(i) - values->at(i)) + values->at(i);
}
