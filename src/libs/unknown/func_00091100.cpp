/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The copy in units of a type, the last first: nothing when less than a
 * unit is left, else an unsigned index from the count's units (the base's
 * `movsxd; shr; dec` and the index's zero extension, `mov eax, eax`, in
 * the loop), the loop on what is left of it (derived name). The early
 * return keeps its own test where the caller has tested the count already
 * (cookbook 346). */
template <typename T> static inline void copyBackwards(void *dst, const void *src, int n)
{
    T *d = static_cast<T *>(dst);
    const T *s = static_cast<const T *>(src);
    unsigned int left = n;
    if (left < sizeof(T)) {
        return;
    }
    unsigned int i = n / sizeof(T) - 1;
    do {
        d[i] = s[i];
        i--;
        left -= sizeof(T);
    } while (left >= sizeof(T));
}

/* Whether a copy can go in units of a type: the count at least one unit
 * and a multiple of it, both addresses aligned to it (derived name). */
template <typename T> static inline bool fitsUnits(const void *dst, const void *src, int n)
{
    return n >= sizeof(T) && (n & (sizeof(T) - 1)) == 0 &&
           (reinterpret_cast<hkUlong>(dst) & (sizeof(T) - 1)) == 0 &&
           (reinterpret_cast<hkUlong>(src) & (sizeof(T) - 1)) == 0;
}

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
