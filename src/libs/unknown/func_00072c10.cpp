/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_hk_algorithm.h"

/* The keyed pointers' sort (0x72400 orders its objects with it). */
// NONMATCHING (0x72c10, a two-copies-of-a-loop shape, NOTES Round 64B): the base scans down from
// j in two loops, one for a null pivot (`cmp qword ptr [rdi-8], 0`) and one for an object, and
// keeps both scans on element pointers, the swap reloading both slots; every comparator spelled
// here keeps one loop with the pivot's test inside it. When it matches, the row is renamed to
// the instantiation's mangled name (cookbook 206).
template void hkAlgorithm::quickSortRecursive(const Keyed00072c10 **pArr, int d, int h,
                                              KeyLess00072c10 cmpLess);
