/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_object016b9108.h"

/* derived names: the types of the nodes whose values the search goes
 * below: a node walking one list, and a node keeping a ring of them */
extern Type00503fb0 *D_58b6258;
extern Type00503fb0 *D_58b6e80;

/* derived names: where a node was found: its value and its state byte */
struct Found0057f430 { /* derived name */
    char *value;
    u8 *state; /* +0x8 */
};

/* derived names: finds a node in a list, then in the lists the list's
 * walking nodes go over, depth first; on success the node's value and
 * state byte are stored and 1 returned, else 0. */
// NONMATCHING: 18/159, 592 bytes against 627: the base loads D_58b6258 once before the loop over the list (`mov rax, [0x58b6258]; mov [rbp-0xc0], rax`) across the recursive calls, which needs the variable local to the link's optimiser (GlobalsModRef: FUN_00bdbb50 alone stores it); D_58b6e80, read in the same loop, is not hoisted. The module keeps both external (config/local_data has no row kind for it). Then the search loop's induction variable (the base counts i - 1 from -1: `mov edx, -1; lea eax, [rdx+1]; add edx, 2`) and the valueAt compares' operand order (`cmp r12, rax; jae`) are open
int FUN_0057f430(Found0057f430 *found, NodeList583950 *list, void *node) /* derived name */
{
    if (!list || !list->count)
        return 0;
    const unsigned count = list->count;
    NodeCursor583950 cursor(list);
    if (cursor.select(node)) {
        found->value = cursor.value();
        found->state = cursor.state();
        return 1;
    }
    for (unsigned i = 0; i < count; ++i) {
        const Type00503fb0 *type = static_cast<Object016b9108 *>(list->items[i])->type;
        if (type == D_58b6258) {
            WalkValue583950 *value = reinterpret_cast<WalkValue583950 *>(list->valueAt(i));
            if (FUN_0057f430(found, value->list, node))
                return 1;
        } else if (type == D_58b6e80) {
            WalkRing583950 *ring = reinterpret_cast<WalkRing583950 *>(list->valueAt(i));
            if (ring->walked == ring->last)
                continue;
            NodeList583950 *lists[16];
            const unsigned first = ring->first;
            const unsigned end = ring->last + 1;
            const unsigned taken = end - first;
            unsigned n = 0;
            for (unsigned k = first; k < end; ++k)
                lists[n++] = ring->lists[k & 15];
            for (unsigned k = 0; k < taken; ++k)
                if (FUN_0057f430(found, lists[k], node))
                    return 1;
        }
    }
    return 0;
}
