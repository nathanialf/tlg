/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: the next node of a list, taken through its owner (which it
 * does not read). FUN_001522a0 walks the list with it until it returns
 * null; its neighbour FUN_000b6cf0 returns the node's payload at +0x10.
 * Classes unknown. */
struct ListNode000b6d00 {
    ListNode000b6d00 *next;
};

struct List000b6d00;

ListNode000b6d00 *FUN_000b6d00(const List000b6d00 *list,
                               const ListNode000b6d00 *node) /* derived name */
{
    return node->next;
}
