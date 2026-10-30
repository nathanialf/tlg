/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

// NONMATCHING: 86 of 88: every instruction but the order of the second
// scan's two induction increments (`inc ecx; inc eax` in the base, here
// the other way; LSR's choice). The entry's copy is member by member (its
// copy constructor), which made the swap's loads the base's (docs/NOTES.md,
// Round 63A).
/* The pair processing's entries sorted by their two bodies' ids (0x717d0
 * calls it at 0x71ac1 and 0x71c8f). */
template void
hkAlgorithm::quickSortRecursive<BodyPairEntry000717d0, hkAlgorithm::less<BodyPairEntry000717d0>>(
    BodyPairEntry000717d0 *, int, int, hkAlgorithm::less<BodyPairEntry000717d0>);
