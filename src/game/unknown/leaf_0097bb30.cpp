/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a grid of 64-byte cells (the array at +0xc0, its width at
 * +0xf4 and its height at +0xfc): the neighbour of the cell at an index in
 * one of four directions (0 to 3, the jump table 0x1558bc4: the row above,
 * the row below, the next column, the previous column), null past the
 * grid's edge or with no cells; an index is clamped to the grid as the cell
 * is taken. With the last argument 1 a cell whose int at +0x24 is zero gives
 * null. What the grid and its cells hold is not traced. */
struct Cell0097bb30 { /* derived name */
    u8 unknown0[0x24];
    int unknown24;
    u8 unknown28[0x18];
};

struct Grid0097bb30 { /* derived name */
    u8 unknown0[0xc0];
    Cell0097bb30 *cells; /* +0xc0 */
    u8 unknownc8[0xf4 - 0xc8];
    int width; /* +0xf4 */
    u8 unknownf8[0x4];
    int height; /* +0xfc */

    /* the cell at an index clamped to the grid */
    Cell0097bb30 *cell(int index) /* derived name */
    {
        int last = width * height - 1;
        if (index < 0)
            index = 0;
        else if (index > last)
            index = last;
        return &cells[index];
    }
};

// NONMATCHING: the clamp's compare: the base tests index <= last (decl, cmp, cmovle) where the
// build tests index < width * height (InstCombine's icmp sgt X, (Y + -1) -> icmp sge X, Y, absent
// from 3.6.2), and in the row below the build drops the clamp to last (sar, andn) and places the
// case last; a probe with last computed unsigned was not equal either
Cell0097bb30 *FUN_0097bb30(Grid0097bb30 *grid, const unsigned &index, int direction,
                           int active) /* derived name */
{
    if (!grid->cells)
        return nullptr;
    unsigned current = index;
    int target;
    Cell0097bb30 *cell;
    switch (direction) {
    case 0:
        target = current - grid->width;
        if (target < 0)
            return nullptr;
        cell = grid->cell(target);
        break;
    case 1:
        target = current + grid->width;
        if (target >= grid->width * grid->height)
            return nullptr;
        cell = grid->cell(target);
        break;
    case 2: {
        int column = current % grid->width;
        if (column + 1 >= grid->width)
            return nullptr;
        cell = grid->cell(current + 1);
        break;
    }
    case 3: {
        int column = current % grid->width;
        if (column <= 0)
            return nullptr;
        cell = grid->cell(current - 1);
        break;
    }
    default:
        return nullptr;
    }
    if (active == 1 && cell && !cell->unknown24)
        return nullptr;
    return cell;
}
