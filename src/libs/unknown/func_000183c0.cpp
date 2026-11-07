/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The blocks sorted by their memory's address: a bottom-up merge sort of
 * the list, runs of one, two, four and on merged in passes until a pass
 * merges once. */
// NONMATCHING: 425 of 447 bytes; the merge (three loops), the head on the
// stack and the counting are the base's; the base also holds a second copy
// of the pass's run loop for runSize <= 0 (0x183fa to 0x18448), the
// two-copies shape D21's addendum leaves to the source (0x92040's twin,
// round 73B's note; NOTES "Round 75A").
FreeListBlock *FUN_000183c0(FreeListBlock *blocks)
{
    if (!blocks) {
        return HK_NULL;
    }
    FreeListBlock *list = blocks;
    int runSize = 1;
    for (;;) {
        FreeListBlock *p = list;
        FreeListBlock *head = HK_NULL;
        FreeListBlock **tail = &head;
        int numMerges = 0;
        while (p) {
            numMerges++;
            FreeListBlock *q = p;
            int pSize = 0;
            while (pSize < runSize && q) {
                pSize++;
                q = q->next;
            }
            int qSize = runSize;
            while (pSize > 0 && qSize > 0 && q) {
                FreeListBlock *e;
                if (p->memory <= q->memory) {
                    e = p;
                    p = p->next;
                    pSize--;
                } else {
                    e = q;
                    q = q->next;
                    qSize--;
                }
                *tail = e;
                tail = &e->next;
            }
            while (pSize > 0) {
                *tail = p;
                tail = &p->next;
                p = p->next;
                pSize--;
            }
            while (qSize > 0 && q) {
                *tail = q;
                tail = &q->next;
                q = q->next;
                qSize--;
            }
            p = q;
        }
        *tail = HK_NULL;
        list = head;
        if (numMerges <= 1) {
            return list;
        }
        runSize *= 2;
    }
}
