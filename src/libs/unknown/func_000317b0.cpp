/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The pair index of every two cells, filled by the space splitter's
 * constructor (0x605b0's file); a missing cell (0xff) is row or column 0. */
extern u8 D_57c1660[17][17];

/* A range linked in after a cell's first one, or made the first when the
 * cell has none. derived name. */
static inline void appendRange(JacobianRange000317b0 &entry, JacobianRange000317b0 *range)
{
    if (entry.numElements == 0) {
        entry = *range;
    } else {
        range->next = entry.next;
        entry.next = range;
    }
}

/* A range filed at a cell of a grid: kept in place when the cell is empty,
 * otherwise copied by the grid's writer and linked in. derived name. */
static inline void addRange(hkArray<JacobianRange000317b0> &grid, hkBlockStreamWriter *writer,
                            int cell, const JacobianRange000317b0 &range)
{
    if (range.numElements == 0) {
        return;
    }
    JacobianRange000317b0 &entry = grid[cell];
    if (entry.numElements == 0) {
        entry = range;
        return;
    }
    JacobianRange000317b0 *copy =
        static_cast<JacobianRange000317b0 *>(writer->reserve(sizeof(JacobianRange000317b0)));
    *copy = range;
    appendRange(entry, copy);
    writer->advance(sizeof(JacobianRange000317b0));
}

// NONMATCHING: 89 of 147, the cells' width (docs/NOTES.md, Round 76B): the base keeps the two
// cells and the cell phi in 32 bits (`movzx ecx, byte [..+0x3e]; cmp ecx, 0xff`, `inc ecx; movzx
// eax, cl`, the pair index `imul ecx, ecx, 0x11; add ecx, eax; movsxd`), the sibling slot 19
// (0x331a0) the same; here InstCombine narrows the compares, the increments and the phi to i8
// (FoldPHIArgOpIntoPHI over one-use zexts), and the registers follow. The selection is one
// insertion after the writer and grid are chosen (three inlined copies otherwise).
void hknpWorldObject380::FUN_000317b0(const SolverContext000317b0 *context,
                                      const hkArray<JacobianRange000317b0 *> &ranges,
                                      hkBlockStreamWriter *writer,
                                      hkArray<JacobianRange000317b0> &grid,
                                      hkBlockStreamWriter *pairWriter,
                                      hkArray<JacobianRange000317b0> &pairGrid)
{
    for (int i = 0; i < ranges.size; i++) {
        const JacobianRange000317b0 *range = ranges[i];
        if (range->numElements == 0) {
            continue;
        }
        hkBlockStreamReader reader;
        reader.FUN_000937f0(range);
        const Pair08Owner *jacobian = static_cast<const Pair08Owner *>(reader.access());

        const hknpWorld *world = context->world;
        const int cellA =
            world->motionManager.motions[world->bodyManager.bodies[jacobian->first].motionId]
                .cellIndex;
        const int cellB =
            world->motionManager.motions[world->bodyManager.bodies[jacobian->second].motionId]
                .cellIndex;
        hkBlockStreamWriter *rangeWriter;
        hkArray<JacobianRange000317b0> *rangeGrid;
        int cell;
        if (cellA == 0xff) {
            rangeWriter = writer;
            rangeGrid = &grid;
            cell = cellB;
        } else if (cellB == 0xff) {
            rangeWriter = writer;
            rangeGrid = &grid;
            cell = cellA;
        } else {
            rangeWriter = pairWriter;
            rangeGrid = &pairGrid;
            cell = D_57c1660[u8(cellB + 1)][u8(cellA + 1)];
        }
        addRange(*rangeGrid, rangeWriter, cell, *range);
    }
}
