/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

BroadPhaseTasks0018d640::~BroadPhaseTasks0018d640()
{
    delete updateDirtyBodiesTask;
    delete exportNewPairsTask;
    delete updateFinishedTask;
    for (int i = 0; i < 8; i++) {
        delete updateLayerTasks[i];
    }
    for (int i = 0; i < 16; i++) {
        delete collideTasks[i];
    }
}
