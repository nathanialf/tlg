/* Havok's sorting helpers (hkAlgorithm, derived names: no string names them;
 * the shape is the public SDK's quick sort). The executable holds the
 * recursive sort once per element type (0x1770 for pointers, 0x15b600 for
 * 32-bit words), each comparing with the default less-than. */
#ifndef TLG_HK_ALGORITHM_H
#define TLG_HK_ALGORITHM_H

namespace hkAlgorithm /* derived name */
{

/* The default order: a before b when a < b. derived name. */
template <typename T> struct less {
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <typename T> inline void swap(T &x, T &y)
{
    T t = x;
    x = y;
    y = t;
}

/* The elements from d to h sorted in place: the middle one the pivot, the
 * lower part sorted by a recursive call and the upper by going round again.
 * The bytes test the scans' meeting as j against i and store the element at
 * j first (both instantiations hold `cmp j, i; jl` and the store to [j]
 * before the store to [i]). derived name. */
template <typename T, typename L> void quickSortRecursive(T *pArr, int d, int h, L cmpLess)
{
    int i, j;
    T str;

begin:
    i = d;
    j = h;
    str = pArr[(d + h) >> 1];
    do {
        while (cmpLess(pArr[i], str)) {
            i++;
        }
        while (cmpLess(str, pArr[j])) {
            j--;
        }
        if (j >= i) {
            if (i != j) {
                swap(pArr[j], pArr[i]);
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (d < j) {
        quickSortRecursive(pArr, d, j, cmpLess);
    }
    if (i < h) {
        d = i;
        goto begin;
    }
}

/* The numElem elements sorted, when there are two at least (the clean
 * step 0x657b0 tests `cmp size, 2; jl` before the call, its sort block
 * next). derived name. */
template <typename T, typename L> inline void quickSort(T *pArr, int numElem, L cmpLess)
{
    if (numElem > 1) {
        quickSortRecursive(pArr, 0, numElem - 1, cmpLess);
    }
}

} // namespace hkAlgorithm

#endif
