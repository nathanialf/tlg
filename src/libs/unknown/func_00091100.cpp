/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The copy in units of a type, the last first: the index from the signed
 * count, the loop on what is left of it (derived name). */
template <typename T> static inline void copyBackwards(void *dst, const void *src, int n)
{
    T *d = static_cast<T *>(dst);
    const T *s = static_cast<const T *>(src);
    int i = int(n / sizeof(T)) - 1;
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

// NONMATCHING: the byte copy and the four tests equal; each wider copy's
// loop differs: the base keeps the loop's guard (`cmp edx, 8; jb` again
// after the tests) and steps a 32-bit index from (sext(n) >> 3) - 1, where
// this compile drops the guard as implied by the tests (GVN) and steps two
// pointers (docs/NOTES.md, Round 62A).
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
