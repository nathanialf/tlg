/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

// NONMATCHING: 9 of 101: the scans' induction variables. The base keeps
// each scan on its index (`movsxd; lea r12, [rcx+2*rcx]` per step, the
// key compared from memory) where this compile walks the second scan with
// a pointer stepped by -0x18, as the key-only sort 0x72980 does in both
// (LSR); the comparator's two-level test is the base's (docs/NOTES.md,
// Round 69A).
/* The pair processing's entries sorted by their first int, then their two
 * bodies' ids (0x717d0 calls it at 0x71aa5, 0x72400 at 0x7246b). */
template void hkAlgorithm::quickSortRecursive<BodyPairEntry000717d0, Value0ThenKeyLess000717d0>(
    BodyPairEntry000717d0 *, int, int, Value0ThenKeyLess000717d0);
