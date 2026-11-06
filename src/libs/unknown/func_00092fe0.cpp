/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: one node waited for through slot 7; for two or more, a
 * node of their own (slots 2 and 3) made to wait on each (slot 5, the pairs
 * in a block of the thread's stack), counted down (slot 6), waited for
 * (slot 7) and given back (slot 9). */
void FUN_00092fe0(Interface168e888 *runner, TaskNode000172c0 *const *nodes, int numNodes)
{
    if (numNodes == 1) {
        runner->FUN_00017930(nodes[0]);
    } else if (numNodes >= 2) {
        TaskNode000172c0 *batch;
        runner->FUN_00017240(&batch, 1);
        runner->FUN_00017280(batch, HK_NULL, 0);
        LocalBuffer<TaskPair000173f0> pairs(numNodes);
        for (int i = 0; i < numNodes; i++) {
            pairs.data[i].node = nodes[i];
            pairs.data[i].successor = batch;
        }
        runner->FUN_000173f0(pairs.data, numNodes);
        runner->FUN_00017540(&batch, 1);
        runner->FUN_00017930(batch);
        runner->FUN_00017260(&batch, 1);
    }
}
