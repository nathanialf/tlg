/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The prepare-new-pairs task's destructor: both vtables restored, the
 * inplace array's storage given back. Its thunks from the task interface
 * at +0x10 (0x15b500, 0x15b560) have the bodies inlined. */
hknpPrepareNewPairsTask::~hknpPrepareNewPairsTask() {}
