/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The compound shapes' instance array's growth (0x410a0; their constructor
 * calls it twice, 0x4134d and 0x413f0). */
// NONMATCHING: the loop and its body are the base's; the base keeps the
// address of firstFree apart on each way to the final store (GVN's PRE
// clone `add r15, 0x10` on the skip path, the preheader's GEP spilled at
// [rbp-0x30] on the loop path), where the late SimplifyCFG's
// HoistThenElseCodeToIf hoists the two identical GEPs into the guard and
// CodeGenPrepare folds the address into both uses, which moves the
// registers (NOTES "Round 75A").
template void
hkFreeListArray<hknpShapeInstance, hknpShapeInstanceId, 8, hknpShapeInstance>::grow(int growBy);
