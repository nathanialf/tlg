/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The broad phase's tasks, each from the thread's heap with this object as
 * its owner: the dirty bodies' update, the export of new pairs, the
 * finish, one update for each of the eight layers and sixteen collide
 * tasks, each with its index. The head (the pool, the layers, the body
 * manager and the stream) is set up for each step (0x18d960). */
BroadPhaseTasks0018d640::BroadPhaseTasks0018d640()
{
    updateDirtyBodiesTask = new hknpBroadPhaseUpdateDirtyBodiesTask(this);
    exportNewPairsTask = new hknpBroadPhaseExportNewPairsTask(this);
    updateFinishedTask = new hknpBroadPhaseUpdateFinishedTask();
    for (int i = 0; i < 8; i++) {
        updateLayerTasks[i] = new hknpBroadPhaseUpdateLayerTask(this, i);
    }
    for (int i = 0; i < 16; i++) {
        collideTasks[i] = new BroadPhaseCollideTask(this, i);
    }
}
