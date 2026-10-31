/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

// NONMATCHING: 9 of 101. The base keeps each scan's two increments in the
// loop's header before the compare (`lea eax, [r15+1]; inc rcx`, the swap's
// i++ and j-- reusing them) and LSR leaves both scans on the index; here
// the increments sit in a latch block reached from both of the comparator's
// exits, so LoopRotate's simplifyLoopLatch (one exiting predecessor) cannot
// fold it, and LSR walks the second scan with a pointer. With the increments
// moved into the headers in this IR and LSR off, the debug llc gives the
// base's shape (docs/NOTES.md, Round 70A).
/* The pair processing's entries sorted by their first int, then their two
 * bodies' ids (0x717d0 calls it at 0x71aa5, 0x72400 at 0x7246b). */
template void hkAlgorithm::quickSortRecursive<BodyPairEntry000717d0, Value0ThenKeyLess000717d0>(
    BodyPairEntry000717d0 *, int, int, Value0ThenKeyLess000717d0);
