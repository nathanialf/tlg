/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The cache's destructor: each loaded buffer given back, then the array
 * and the two maps. */
Object0019a7c0::~Object0019a7c0()
{
    for (int i = 0; i < buffers.size; i++) {
        FUN_0019bb80(buffers.data[i]);
    }
}
