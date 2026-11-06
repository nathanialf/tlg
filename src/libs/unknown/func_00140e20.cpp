/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The broad phase's trees by layer destroyed (the compiler's D0 at 0x140e20
 * and D1 at 0x140e70): each layer's tree and the tasks deleted, then the
 * marked bodies, the layer pairs and the configuration's reference. */
BroadPhaseLayers00142a40::~BroadPhaseLayers00142a40()
{
    for (int i = 0; i < numLayers; i++) {
        delete trees[i];
    }
    delete tasks;
}
