/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: every column of both read first, then each result column
 * from the same lane of b's columns (the header's setMulTransposed). */
void hkMatrix3::FUN_0001abb0(const hkMatrix3 &a, const hkMatrix3 &b)
{
    setMulTransposed(a, b);
}
