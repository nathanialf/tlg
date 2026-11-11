/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_libc.h"

/* derived names: frees every block of the singly linked list whose head the
 * object holds (the next block at +0x8 of each), leaving the head null; its
 * address is taken by FUN_00d24640 (lea at 0xd2466f). The types are not
 * traced. */
struct Block00d24810 { /* derived name */
    u8 unknown0[8];
    Block00d24810 *next;
};

struct List00d24810 { /* derived name */
    Block00d24810 *head;
};

void FUN_00d24810(List00d24810 *list) /* derived name */
{
    while (Block00d24810 *block = list->head) {
        list->head = block->next;
        free(block);
    }
}
