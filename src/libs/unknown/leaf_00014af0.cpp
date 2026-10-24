/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: push onto an intrusive singly linked list whose head is at
 * +8 and whose count is at +0x70. Unknown owner. */
struct ListNode {
    ListNode *next;
};

struct CountedList {
    void *unknown0;
    ListNode *head;
    u8 unknown10[0x60];
    s64 count;
};

void FUN_00014af0(CountedList *list, ListNode *node) /* derived name */
{
    list->count++;
    node->next = list->head;
    list->head = node;
}
