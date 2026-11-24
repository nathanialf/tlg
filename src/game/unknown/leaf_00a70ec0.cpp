/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: a square grid of size x size cells of a tenth of a unit,
 * each cell a pointer to an array of indices (null for an empty cell);
 * FUN_00a69120 and FUN_00a6f1b0 pass a rectangle (each bound moved by the
 * float at +0x80 of their object) and a local locked array to collect the
 * indices in. The scale 10.0 is the constant at 0x14d87d4. */
static inline int cellOf(float coordinate, int last) /* derived name */
{
    const int cell = int(coordinate * 10.0f);
    return cell < 0 ? 0 : (cell <= last ? cell : last);
}

/* FUN_00a70ec0: the rectangle's cells, row by row, each cell's indices added
 * to the list once: the list searched (contains) and the index pushed, each
 * inline, where FUN_00c14850 and FUN_00d4a7a0 call the list's addUnique
 * (FUN_00c149a0, cost 230 at stage 1 against the threshold of 225). The
 * base splits the rows' loop on x0 <= x1 (0xa70f56: the empty copy), the
 * unit pipeline's LoopUnswitch (docs/DECISIONS.md D92). */
void FUN_00a70ec0(Array01343a80<int> *indices, int size, Array05943280<u32> *const *cells,
                  float left, float top, float right, float bottom) /* derived name */
{
    const int last = size - 1;
    const unsigned x0 = cellOf(left, last);
    const unsigned y0 = cellOf(top, last);
    const unsigned x1 = cellOf(right, last);
    const unsigned y1 = cellOf(bottom, last);
    for (unsigned y = y0; y <= y1; ++y) {
        for (unsigned x = x0; x <= x1; ++x) {
            const Array05943280<u32> *cell = cells[y * size + x];
            if (cell == 0)
                continue;
            for (unsigned i = 0; i < cell->size(); ++i) {
                const int index = cell->at(i);
                if (!indices->contains(index))
                    indices->push(index);
            }
        }
    }
}
