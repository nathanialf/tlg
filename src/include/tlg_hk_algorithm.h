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

/* The temporary built, then assigned: a record whose constructor sets a
 * field keeps that field apart from the rest of the copy (the record sort
 * 0x62130 moves its first twelve bytes through the stack and the count
 * through a register); the same for every type with a trivial constructor.
 * The temporary on a 16-byte boundary, as the pivot (the locked elements'
 * sort, 0x24c00, keeps its 7-byte one at rbp-0x40 under the guard at -0x30,
 * the pivot at -0x50). derived name. */
template <typename T> inline void swap(T &x, T &y)
{
    T t __attribute__((aligned(16)));
    t = x;
    x = y;
    y = t;
}

/* The elements from d to h sorted in place: the middle one the pivot, the
 * lower part sorted by a recursive call and the upper by going round again.
 * The bytes test the scans' meeting as j against i and store the element at
 * j first (both instantiations hold `cmp j, i; jl` and the store to [j]
 * before the store to [i]); the two are told apart as j against i too, which
 * orders LSR's two counters of the second scan as the base has them (0x72980).
 * derived name. */
template <typename T, typename L> void quickSortRecursive(T *pArr, int d, int h, L cmpLess)
{
    int i, j;
    /* The pivot on a 16-byte boundary, as Havok aligns it: the vertex
     * format's 8-byte elements (0x26f20) keep it at rbp-0x40 under the guard
     * at -0x30, the eight bytes between unused. */
    T str __attribute__((aligned(16)));

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
            if (j != i) {
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
