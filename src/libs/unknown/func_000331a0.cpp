/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The pair index of every two cells, filled by the space splitter's
 * constructor (0x605b0's file); a missing cell (0xff) is row or column 0. */
extern u8 D_57c1660[17][17];

/* A range linked in after a cell's first one, or made the first when the
 * cell has none. derived name. */
static inline void appendRange(CacheRange000331a0 &entry, CacheRange000331a0 *range)
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
static inline void addRange(hkArray<CacheRange000331a0> &grid, CacheWriter00031a30 *writer,
                            int cell, const CacheRange000331a0 &range)
{
    if (range.numElements == 0) {
        return;
    }
    CacheRange000331a0 &entry = grid[cell];
    if (entry.numElements == 0) {
        entry = range;
        return;
    }
    CacheRange000331a0 *copy =
        static_cast<CacheRange000331a0 *>(writer->reserve(sizeof(CacheRange000331a0)));
    *copy = range;
    appendRange(entry, copy);
    writer->advance(sizeof(CacheRange000331a0));
}

// NONMATCHING: 0x317b0's cells' width (docs/NOTES.md, Round 83A): equal but for the cells, which
// the base keeps in 32 bits (`movzx eax, byte [..+0x3e]; cmp eax, 0xff`, the phi `mov r13d, eax`,
// the pair index `imul ecx, ecx, 0x11; add ecx, eax; movsxd`) where InstCombine narrows them to i8
// here (the phi zero-extended before `shl r13, 6`, the index in 64 bits); a switch on the first
// cell and a flat index into the table compile the same.
void hknpWorldObject380::FUN_000331a0(const SolverContext000317b0 *context,
                                      const hkArray<CacheRange000331a0 *> &ranges,
                                      CacheWriter00031a30 *writer,
                                      hkArray<CacheRange000331a0> &grid,
                                      CacheWriter00031a30 *pairWriter,
                                      hkArray<CacheRange000331a0> &pairGrid)
{
    const int numRanges = ranges.size;
    for (int i = 0; i < numRanges; i++) {
        const CacheRange000331a0 *range = ranges[i];
        if (range->numElements == 0) {
            continue;
        }
        hkBlockStreamReader reader;
        reader.FUN_000937f0(range);
        const Pair08Owner *cache = static_cast<const Pair08Owner *>(reader.access());
        do {
            const hknpWorld *world = context->world;
            const int cellA =
                world->motionManager.motions[world->bodyManager.bodies[cache->first].motionId]
                    .cellIndex;
            const int cellB =
                world->motionManager.motions[world->bodyManager.bodies[cache->second].motionId]
                    .cellIndex;
            CacheWriter00031a30 *cacheWriter;
            hkArray<CacheRange000331a0> *cacheGrid;
            int cell;
            if (cellA == 0xff) {
                cacheWriter = writer;
                cacheGrid = &grid;
                cell = cellB;
            } else if (cellB == 0xff) {
                cacheWriter = writer;
                cacheGrid = &grid;
                cell = cellA;
            } else {
                cacheWriter = pairWriter;
                cacheGrid = &pairGrid;
                cell = D_57c1660[u8(cellB + 1)][u8(cellA + 1)];
            }

            CacheRange000331a0 cacheRange;
            cacheRange.setStartPoint(cacheWriter);
            cacheWriter->stats.totalSize = 0;
            cacheWriter->stats.maxCount = 0;
            Pair08Target *target = cache->target;
            hkBlockStreamBlock *writtenBlock;
            const Pair08Owner *written =
                FUN_00031a30(cache, target, cache->count, cache->type, cache->unknown4, &reader,
                             cacheWriter, &writtenBlock);
            if (target) {
                const hkBlockStreamBlock *block = cacheWriter->currentBlock;
                target->recordBlock = block;
                target->recordOffset = u16(reinterpret_cast<const char *>(written) -
                                           reinterpret_cast<const char *>(block));
            }
            cacheRange.FUN_00092220(cacheWriter);
            cacheRange.stats = cacheWriter->stats;
            addRange(*cacheGrid, cacheWriter, cell, cacheRange);
            cache = static_cast<const Pair08Owner *>(reader.access());
        } while (cache);
    }
}
