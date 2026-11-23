/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the node FUN_00c02390 is given: the nodes it chooses
 * among at +0x30 */
struct Node00c02390 { /* derived name */
    u8 unknown0[0x30];
    Node583950 **choices; /* +0x30 */
};

/* derived names: the node's value in the owner's list: the index of the
 * chosen node at +0x4 */
struct Record00c02390 { /* derived name */
    u8 unknown0[0x4];
    int chosen; /* +0x4 */
};

/* derived names: a handler whose address FUN_00be6da0 takes: the node is
 * made the current one of the owner's list and the node its value chooses
 * is made the current one after it; when that node's state byte is 1 it
 * is handed to the handler of its kind. Returns 0. Handler unknown. */
int FUN_00c02390(Owner583950 *self, void *arg) /* derived name */
{
    Node00c02390 *node = static_cast<Node00c02390 *>(arg);
    unsigned found;
    if (!self->find(node, found))
        return 0;
    self->cursor.current = found;
    Record00c02390 *record = reinterpret_cast<Record00c02390 *>(self->currentValue());
    if (!record)
        return 0;
    Node583950 *chosen = node->choices[record->chosen];
    u8 *state = self->selectState(chosen);
    if (state && *state == 1)
        self->dispatch(chosen);
    return 0;
}
