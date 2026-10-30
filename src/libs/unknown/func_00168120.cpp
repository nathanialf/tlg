/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_00168120(const hkArray<hkBlockStreamLinkedRange> &ranges,
                  hkPrimaryCommandDispatcher &dispatcher) /* derived name */
{
    for (int i = 0; i < ranges.getSize(); i++) {
        const hkBlockStreamLinkedRange *range = &ranges[i];
        if (range->numElements == 0) {
            continue;
        }
        do {
            hkBlockStreamReader reader;
            reader.FUN_000937f0(range);
            for (const hkCommand *command = static_cast<const hkCommand *>(reader.access());
                 command; command = static_cast<const hkCommand *>(
                              reader.advance(command->sizePaddedTo16))) {
                dispatcher.FUN_00090830(*command);
            }
            range = range->next;
        } while (range);
    }
}
