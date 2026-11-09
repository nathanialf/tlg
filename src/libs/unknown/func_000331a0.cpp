/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The pair index of every two cells, filled by the space splitter's
 * constructor (0x605b0's file); a missing cell (0xff) is row or column 0. */
extern u8 D_57c1660[17 * 17];

// NONMATCHING: the second arm's phi copies (189 of 191, 833 bytes as the base): for a missing
// second cell the base reloads the grid and the writer before the cell's copy `mov r13d, eax`,
// here the cell's copy comes between the two reloads. The cells' width of round 83A was the pair
// index: `(cell + 1) & 0xff` keeps the add in 32 bits where `u8(cell + 1)` narrows it, and the
// flat index `row * 17 + column` gives the base's `imul ecx; add ecx; movsxd` (docs/NOTES.md,
// Round 87A). The grid declared before the writer orders the first arm's reloads as the base's.
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
            hkArray<CacheRange000331a0> *cacheGrid;
            CacheWriter00031a30 *cacheWriter;
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
                cell = D_57c1660[((cellB + 1) & 0xff) * 17 + ((cellA + 1) & 0xff)];
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
