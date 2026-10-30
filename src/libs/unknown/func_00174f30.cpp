/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Every record of the array cleared. derived name. */
static void resetEntries(hkArray<hknpWorldStreams260::EntryC20> &entries) /* derived name */
{
    for (int i = 0; i < entries.size; i++) {
        entries[i].reset();
    }
}

void hknpWorldStreams260::FUN_00174f30(CommandStreams00167f70 *context) /* derived name */
{
    if (stream400.stream.numTotalElements == 0) {
        return;
    }
    resetEntries(arrayC20);
    FUN_000717d0(context, &stream400, &stream500, &arrayC20, 0);
    stream200.stream.FUN_00094a10(context->cache, &stream400.stream);
    stream300.stream.FUN_00094a10(context->cache, &stream500.stream);
    stream400.stream.FUN_00094880(context->cache);
    stream500.stream.FUN_00094880(context->cache);
}
