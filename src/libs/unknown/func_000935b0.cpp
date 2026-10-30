/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The code of a float: zero below the smallest code's value, else a binary
 * search over the 256 codes, seven halvings and an eighth probe that rounds
 * the last code up when the float lies above it (the table's last code
 * excepted). Each probe reads the float before the table: it is a
 * reference the out-of-line table read might write. */
hkUFloat8 &hkUFloat8::operator=(const float &fv)
{
    hkUFloat8 smallest;
    smallest.value = 1;
    if (smallest.getReal() > fv) {
        value = 0;
        return *this;
    }
    int lo = 0;
    int hi = 256;
    int mid = 128;
    for (int i = 6;; i--) {
        hkUFloat8 probe;
        probe.value = u8(mid);
        const bool above = fv > probe.getReal();
        if (i < 0) {
            if (above && mid < 255) {
                mid++;
            }
            break;
        }
        if (above) {
            lo = mid;
        } else {
            hi = mid;
        }
        mid = (lo + hi) >> 1;
    }
    value = u8(mid);
    return *this;
}
