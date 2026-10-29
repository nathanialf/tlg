/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldObject4f8::FUN_00063620()
{
    const int numPending = unknown58.getSize();
    for (int i = 0; i < numPending; i++) {
        if (unknown58[i]) {
            unknown58[i]->index5c = ids68.getSize() - int80;
            ids68.pushBack(unknown58[i]->id50);
        }
    }
    unknown58.clear();
}
