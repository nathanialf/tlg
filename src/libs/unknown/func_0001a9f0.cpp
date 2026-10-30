/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: a's columns read once, then b's columns transformed from
 * the last, each stored before the next is read. */
void hkMatrix3::FUN_0001a9f0(const hkMatrix3 &a, const hkMatrix3 &b)
{
    setMul(a, b);
}
