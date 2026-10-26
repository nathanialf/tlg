/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the number of nodes in a list. */
int FUN_000188a0(const ListNode000188a0 *node) /* derived name */
{
    int count = 0;
    for (; node; node = node->next) {
        count++;
    }
    return count;
}
