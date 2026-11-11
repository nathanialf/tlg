/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: unlinks a node of a doubly linked list (the previous node at
 * +0x0, the next at +0x8) and clears both links. Its address is taken at 19
 * sites, the first in FUN_002030d0. */
struct Link00cb57b0 { /* derived name */
    Link00cb57b0 *previous;
    Link00cb57b0 *next;
};

void FUN_00cb57b0(Link00cb57b0 *link) /* derived name */
{
    if (link->previous) {
        link->previous->next = link->next;
    }
    if (link->next) {
        link->next->previous = link->previous;
    }
    link->previous = 0;
    link->next = 0;
}
