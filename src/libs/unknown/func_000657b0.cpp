/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

// NONMATCHING: 287 bytes against 339: the base keeps the context, the
// shared data and the stream in rax, rsi and rcx through the sort and the
// dedup and moves them through callee-saved registers around each record's
// call (0x658a0 to 0x658c8), its first test `cmp edx, 2; jl` where this
// compile tests `cmp edx, 1; jle`; the dedup and its 16-byte copy are the
// base's.
/* The first step of cleaning the inactive caches (0x657b0, the clean task's
 * 0x14efe2): the records sorted, each one equal to the last kept one (or
 * both without a count) dropped in place, the count left as it was; every
 * record handled, the stream put back in order through the context's cache,
 * and the records emptied. derived name. */
void FUN_000657b0(hknpWorldObject4f8 *self, hknpWorldContextPool::Context *context,
                  const ModifierSharedData *shared, hkBlockStream *stream)
{
    hkArray<SortRecord00062100> &records = self->sortRecords;
    if (records.getSize() > 1) {
        hkAlgorithm::quickSortRecursive(records.data, 0, records.getSize() - 1, FUN_00062100);
        const int numRecords = records.getSize();
        SortRecord00062100 *data = records.data;
        int last = 0;
        for (int i = 1; i < numRecords; i++) {
            const SortRecord00062100 &record = data[i];
            const SortRecord00062100 &kept = data[last];
            if ((kept.count | record.count) == 0 || kept == record) {
                continue;
            }
            last++;
            data[last] = record;
        }
    }
    for (int i = 0; i < records.getSize(); i++) {
        FUN_00065910(context, shared, &records.data[i]);
    }
    stream->FUN_00094c60(context->cache258);
    records.size = 0;
}
