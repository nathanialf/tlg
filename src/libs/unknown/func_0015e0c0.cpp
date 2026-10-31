/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_hk_thread.h"

// NONMATCHING: 4 of 100: the swap. The base copies the temporary as
// slices of the cell (no tail past the cell bytes) and assigns each cell
// field by field (the weight, the range as one vector, then each cell
// byte), where this compile copies 32 bytes twice (docs/NOTES.md, Round
// 69A).
/* The collide task's cells sorted heaviest first (0x15e7d4 jumps to it). */
template void
hkAlgorithm::quickSortRecursive<hknpCollidePairsTask::Entry20, hknpCollidePairsTask::HeavierFirst>(
    hknpCollidePairsTask::Entry20 *, int, int, hknpCollidePairsTask::HeavierFirst);
