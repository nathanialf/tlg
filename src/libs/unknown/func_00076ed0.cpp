/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The pair index of every two cells, filled by the space splitter's
 * constructor (0x605b0's file); a missing cell (0xff) is row or column 0. */
extern u8 D_57c1660[17][17];

/* A cache's range handed on to be filed at a grid cell (derived names;
 * primary type 3, secondary type 4, 0x60 bytes): the record's first int,
 * the range, the grid and the cell. */
struct CacheRangeCommand00076ed0 : public hkCommand /* derived name */
{
    CacheRangeCommand00076ed0(int newId) : hkCommand(0x60, 3, 4), id(newId) {}

    int id;
    u8 unknownc[4];
    CacheRange000331a0 range;
    hkArray<CacheRange000331a0> *grid;
    int cell;
};

// NONMATCHING: greedy's assignment (167 of 199 lines in place, 874 against 887 bytes, the frame
// 0x88 against 0x98): across the two cell calls the base keeps this, the stream and the world in
// registers and spills the cache pointer at entry, the context after its load and the first cell
// as a byte (-0xb0, -0xa8, -0xb1); here this is spilled at entry and the cell kept in r15b, every
// register after that rotated. The rest is the base's: the cells as bytes from their getters, the
// pair index as `(cell + 1) & 0xff` in 32 bits (docs/NOTES.md, Round 87A).
void Elements000760c0::FUN_00076ed0(const Pair08Owner *cache)
{
    hkBlockStream *stream = &elements[0].slots[1];
    ElementsContext00077250 *context = simulationContext;
    const hknpWorld *world = context->world;
    const u8 cellA = FUN_00034990(world, cache);
    const u8 cellB = FUN_000349a0(world, cache);
    const int cell = D_57c1660[(cellB + 1) & 0xff][(cellA + 1) & 0xff];

    CacheWriter00031a30 writer;
    writer.FUN_000938c0(context->cache270, stream);
    CacheRange000331a0 range;
    range.setStartPoint(&writer);
    writer.stats.totalSize = 0;
    writer.stats.maxCount = 0;
    FUN_000319f0(cache, HK_NULL, HK_NULL, &writer, HK_NULL);
    range.FUN_00092220(&writer);
    range.stats = writer.stats;

    if (elements.size == 1) {
        addRange(cacheGrid, &writer, cell, range);
    } else {
        CacheRangeCommand00076ed0 *command =
            new (context->commandWriter->writer.reserve(sizeof(CacheRangeCommand00076ed0)))
                CacheRangeCommand00076ed0(FUN_00010650(cache));
        command->unknown2 = 1;
        command->grid = &cacheGrid;
        command->cell = cell;
        command->range = range;
        context->commandWriter->writer.advance(sizeof(CacheRangeCommand00076ed0));
    }
    writer.FUN_00093a10();
}
