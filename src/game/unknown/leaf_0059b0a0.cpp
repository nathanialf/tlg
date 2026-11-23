/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <algorithm>

#include "tlg_device_thunk.h"
#include "tlg_libc.h"

/* derived names: a node choosing one of its children: bit 0 of its flags
 * at +0x28 chooses at random, the children at +0x30 and their count at
 * +0x38 */
struct ChoiceNode0059b0a0 { /* derived name */
    u8 unknown0[0x28];
    unsigned flags; /* +0x28 */
    u8 unknown2c[4];
    Node583950 **children; /* +0x30 */
    unsigned count;        /* +0x38 */
};

/* derived names: what such a node keeps in the owner's list: the child to
 * start from and the child chosen */
struct Choice0059b0a0 { /* derived name */
    int start;
    int chosen; /* +0x4 */
};

/* derived names: a handler: a node found in the owner's list chooses a
 * child in the state 0 (at random, or its start kept within the children;
 * a node without children gives the chosen -1 and the state 2), clears
 * its children's states and dispatches the chosen one; in the states 1
 * and 2 it dispatches the chosen child again; the owner's +0xd8 becomes
 * the state. Returns 0. Handler unknown. */
// NONMATCHING: 48/150, 463 bytes against 467: the base keeps the start's clamp as a load through a select of addresses (`mov [rbp-0x2c], eax` the last index, `cmp edx, eax; lea rdx, [rbp-0x2c]; cmovl rdx, r13; mov ecx, [rdx]`, std::min's reference) after a branch on start < 0, where the unit's SROA speculates the loads and gives two cmovs; with the value's address in a register as data the base also materialises it once (`add r13, [rax+0x28]`) and merges the two -1 stores into one qword; the flags are loaded as a dword and tested in a register (`mov ecx, [r15+0x28]; test cl, 1`)
int FUN_0059b0a0(Owner583950 *self, ChoiceNode0059b0a0 *node) /* derived name */
{
    Handler583950 *table = self->handlers;
    if (!self->cursor.select(node))
        return 0;
    u8 *state = self->cursor.state();
    Choice0059b0a0 *choice = reinterpret_cast<Choice0059b0a0 *>(self->cursor.value());
    int next = *state;
    switch (next) {
    case 0:
        if (!node->count) {
            choice->start = -1;
            choice->chosen = -1;
            next = 2;
            break;
        }
        if (node->flags & 1) {
            choice->chosen = rand() % node->count;
        } else {
            const int last = node->count - 1;
            choice->chosen = choice->start < 0 ? 0 : std::min(last, choice->start);
        }
        for (unsigned i = 0; i < node->count; ++i)
            self->clearState(node->children[i]);
    case 1:
    case 2: {
        Node583950 *child = node->children[choice->chosen];
        if (child && child->kind) {
            Handler583950 handler = table[child->kind];
            if (handler)
                handler(self, child);
        }
        next = self->unknownd8;
        break;
    }
    }
    *state = next;
    return 0;
}
