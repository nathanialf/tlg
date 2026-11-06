/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* An element of a list linked through its first word. derived name. */
struct ListElement00092040 /* derived name */
{
    ListElement00092040 *next;
};

/* A list sorted by address (0x92040): a bottom-up merge sort, runs of one
 * element merged into runs of two, then four, onto a local head, until a
 * pass merges no more than once. */
// NONMATCHING: 418 bytes against 431, D21's unswitch shape (a fifth witness, reported, not
// worked): the base holds two copies of the pass's run loop, split on the run counter's
// loop-invariant guard `runSize > 0` (0x92072: `test r9d, r9d; jg`), the copy for a
// non-positive size keeping only the q appends; this compile keeps one loop with the guard
// inside it (the counting loop rotated as the base's, its test `pSize + 1 < runSize` before
// the q test; the merge, the p appends and the q appends as the base's tail, 0x920d5 to 0x921b6).
void *FUN_00092040(void *elements)
{
    ListElement00092040 *list = static_cast<ListElement00092040 *>(elements);
    if (!list) {
        return HK_NULL;
    }
    int runSize = 1;
    for (;;) {
        ListElement00092040 head;
        head.next = HK_NULL;
        ListElement00092040 *tail = &head;
        ListElement00092040 *p = list;
        int numMerges = 0;
        while (p) {
            numMerges++;
            ListElement00092040 *q = p;
            int pSize = 0;
            while (pSize < runSize && q) {
                pSize++;
                q = q->next;
            }
            int qSize = runSize;
            while (pSize > 0 && qSize > 0 && q) {
                ListElement00092040 *e;
                if (p <= q) {
                    e = p;
                    p = p->next;
                    pSize--;
                } else {
                    e = q;
                    q = q->next;
                    qSize--;
                }
                tail->next = e;
                tail = e;
            }
            while (pSize > 0) {
                tail->next = p;
                tail = p;
                p = p->next;
                pSize--;
            }
            while (qSize > 0 && q) {
                tail->next = q;
                tail = q;
                q = q->next;
                qSize--;
            }
            p = q;
        }
        tail->next = HK_NULL;
        list = head.next;
        if (numMerges <= 1) {
            return list;
        }
        runSize *= 2;
    }
}
