/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The copy in units of a type, the last first: an unsigned index from the
 * count's units (the base's `movsxd; shr; dec` and the index's zero
 * extension, `mov eax, eax`, in the loop), the loop on what is left of it
 * (derived name). */
template <typename T> static inline void copyBackwards(void *dst, const void *src, int n)
{
    T *d = static_cast<T *>(dst);
    const T *s = static_cast<const T *>(src);
    unsigned int i = n / sizeof(T) - 1;
    for (unsigned int left = n; left >= sizeof(T); left -= sizeof(T)) {
        d[i] = s[i];
        i--;
    }
}

/* Whether a copy can go in units of a type: the count at least one unit
 * and a multiple of it, both addresses aligned to it (derived name). */
template <typename T> static inline bool fitsUnits(const void *dst, const void *src, int n)
{
    return n >= sizeof(T) && (n & (sizeof(T) - 1)) == 0 &&
           (reinterpret_cast<hkUlong>(dst) & (sizeof(T) - 1)) == 0 &&
           (reinterpret_cast<hkUlong>(src) & (sizeof(T) - 1)) == 0;
}

// NONMATCHING: every instruction but the wide loops' guards: the base keeps
// `cmp edx, 8; jb` (4, 2) before each wide loop, which here goes: the
// helper's rotated guard is the test's own `icmp ugt n, 7` (EarlyCSE merges
// the two after inlining), JumpThreading threads the bool phi of fitsUnits
// before GVN, and GVN's equality propagation on the test's `and` then
// folds the guard (docs/NOTES.md, Round 63A).
void FUN_00091100(void *dst, const void *src, int n)
{
    if (fitsUnits<u64>(dst, src, n)) {
        copyBackwards<u64>(dst, src, n);
    } else if (fitsUnits<u32>(dst, src, n)) {
        copyBackwards<u32>(dst, src, n);
    } else if (fitsUnits<u16>(dst, src, n)) {
        copyBackwards<u16>(dst, src, n);
    } else {
        copyBackwards<u8>(dst, src, n);
    }
}
