/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The job queues' ring grown (called by 0x5020, 0x58b0 and 0x61a0): the
 * instance over the 256-byte entries. */
template void hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(int n);
