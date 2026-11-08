/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The hardware setup's assignment, the compiler's member-by-member body
 * kept out of line (the base calls it from the queue's constructor). */
// NONMATCHING: inline-cost margin: the list's _copyFromArray (reserve, the
// dropped lists freed, the kept ones assigned at their exact size, the new
// ones copied) is priced 330 against the hint's 325 (debug opt
// -debug-only=inline), one InstrCost over, so it stays a call where the base
// inlines it (53 of 829 bytes). The base copies the new lists at their exact
// size, where hkArray's copy constructor appends (docs/NOTES.md, Round 83A).
hkJobQueueHwSetup &hkJobQueueHwSetup::operator=(const hkJobQueueHwSetup &other) = default;
