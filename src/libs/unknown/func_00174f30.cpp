/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: equal but for the clear loop's two induction variables' registers (the base's
// count in eax and offset in rcx, swapped here); llc on this TU's own IR, reparsed, gives the
// base's, so the use-list order LSR walks decides it (NOTES Round 61B).
void hknpWorldStreams260::FUN_00174f30(CommandStreams00167f70 *context) /* derived name */
{
    if (stream400.stream.numTotalElements == 0) {
        return;
    }
    for (int i = 0; i < arrayC20.size; i++) {
        arrayC20[i].reset();
    }
    FUN_000717d0(context, &stream400, &stream500, &arrayC20, 0);
    stream200.stream.FUN_00094a10(context->cache, &stream400.stream);
    stream300.stream.FUN_00094a10(context->cache, &stream500.stream);
    stream400.stream.FUN_00094880(context->cache);
    stream500.stream.FUN_00094880(context->cache);
}
