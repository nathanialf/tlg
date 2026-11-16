/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node of the kind FUN_00588200 is given: the node whose
 * state it resets and hands on at +0x28, the nodes it walks at +0x60 */
struct ListNode588200 { /* derived name */
    u8 unknown0[0x28];
    Node583950 *child; /* +0x28 */
    u8 unknown30[0x30];
    Node583950 **children; /* +0x60 */
    unsigned count;        /* +0x68 */
};

void FUN_00c0c640(ListNode588200 *node, void *argument); /* derived name */
int FUN_00c059a0(ValueOwner583950 *self, void *node);    /* derived name */

/* derived names: a handler of the table at +0x9a0 of FUN_00525530's object
 * (kind 32): when its node is in the list, the node's state 0 becomes 1 and
 * the state of the node at +0x28 is reset; in state 0 or 1 the node is
 * given to FUN_00c0c640 with the owner's +0x100, its value counts one more
 * walk, and each node at +0x60 is walked by FUN_00c059a0 with an 'XFIT'
 * owner built from this 'XAIT' one (the handlers at +0x158, else the
 * default table FUN_00525530 also gives the table at +0x42a0); then the node
 * at +0x28 is dispatched. Returns 0. Handler unknown. */
// NONMATCHING: 214/216 by --module, the same size: the default table's four handlers no file
// defines yet (FUN_00c65c00, FUN_00c65ce0, FUN_00c65ff0, FUN_00c05e90, another band's) are
// taken from the GOT (`mov rax, [rip+...]`) where the base has `lea`; every other instruction
// is the base's. Claimable once the four are in the module.
int FUN_00588200(FrameOwner583950 *self, void *arg) /* derived name */
{
    ListNode588200 *node = static_cast<ListNode588200 *>(arg);
    Node583950 *child = node->child;
    unsigned found;
    if (!self->find(node, found))
        return 0;
    self->cursor.current = found;
    int *value = reinterpret_cast<int *>(self->currentValue());
    if (!value)
        return 0;
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0: {
        *state = 1;
        const unsigned saved = self->cursor.current;
        if (self->cursor.select(child))
            self->cursor.list->states[self->cursor.current] = 0;
        self->cursor.current = saved;
    }
    case 1: {
        FUN_00c0c640(node, self->unknown100);
        const int depth = ++*value;
        HandlerTable583950 table;
        Handler583950 *handlers = self->valueHandlers;
        if (!handlers) {
            table.setValueDefaults();
            handlers = table.handlers;
        }
        Node583950 **const end = node->children + node->count;
        for (Node583950 **it = node->children; it != end; ++it) {
            Node583950 *walked = *it;
            ValueOwner583950 owner(*self, handlers, depth);
            FUN_00c059a0(&owner, walked);
        }
        break;
    }
    }
    self->dispatch(child);
    return 0;
}
