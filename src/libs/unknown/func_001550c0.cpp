/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* The build-constraints task's constructor (derived names): its arguments
 * kept, the count cleared. */
// NONMATCHING: equal but for the vtable 0x16a46c0 (address point 0x16a46d0,
// the second base's at 0x16a4718), which has no row (docs/NOTES.md, Round 31).
hknpBuildConstraintsTask::hknpBuildConstraintsTask(int unknown18, void *unknown28, void *unknown20,
                                                   void *unknown30)
    : unknown18(unknown18), unknown20(unknown20), unknown28(unknown28), unknown30(unknown30),
      unknown38(0)
{
}
