/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* The first step of cleaning the inactive caches (0x657b0, the clean task's
 * 0x14efe2): the records sorted, each one equal to the last kept one (or
 * both without a count) dropped in place, the count left as it was; every
 * record handled, the stream put back in order through the context's cache,
 * and the records emptied. The per-record step takes the stream too (its
 * fourth argument, kept in rcx across the loop). derived name. */
void FUN_000657b0(hknpWorldObject4f8 *self, hknpWorldContextPool::Context *context,
                  const ModifierSharedData *shared, hkBlockStream *stream)
{
    hkArray<SortRecord00062100> &records = self->sortRecords;
    hkAlgorithm::quickSort(records.data, records.getSize(), FUN_00062100);
    const int numRecords = records.getSize();
    SortRecord00062100 *data = records.data;
    int last = 0;
    for (int i = 1; i < numRecords; i++) {
        const SortRecord00062100 &record = data[i];
        const SortRecord00062100 &kept = data[last];
        if ((record.count | kept.count) == 0 || kept == record) {
            continue;
        }
        last++;
        data[last] = record;
    }
    for (int i = 0; i < records.getSize(); i++) {
        FUN_00065910(context, shared, &records.data[i], stream);
    }
    stream->FUN_00094c60(context->cache258);
    records.size = 0;
}
