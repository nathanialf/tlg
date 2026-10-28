/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: every entry of every record whose word at +0xc is set,
 * counted, with the splitter's own count added. */
int hknpGridSpaceSplitter::FUN_0018e380(const SplitterRecord0018e380 *records, int numRecords) const
{
    int count = 0;
    for (int i = 0; i < numRecords; i++) {
        const SplitterRecord0018e380 &record = records[i];
        for (int j = 0; j < record.count; j++) {
            if (*reinterpret_cast<const int *>(record.data + j * record.stride + 0xc)) {
                count++;
            }
        }
    }
    return count + unknown1c;
}
