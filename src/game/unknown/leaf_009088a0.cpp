/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an open list of a search, a binary heap of node pointers
 * ordered by the float at +0x10 of each node, the least first. */
struct HeapNode009088a0 { /* derived name */
    u8 unknown0[0x10];
    float cost; /* +0x10 */
};

struct Heap009088a0 {         /* derived name */
    HeapNode009088a0 **nodes; /* +0x0 */
    u32 capacity;             /* +0x8 */
    int count;                /* +0xc */
};

/* derived name: the heap's top taken: the hole left at the root moved down to
 * a leaf along the lesser children, then `node` (the last node, the count
 * already decremented by the caller) put in it and moved up while its parent
 * costs more; called from 0x916742, 0x917f2e and 0x918ed3. */
// NONMATCHING: register assignment only (the base carries the hole in eax and gives the
// early exit its own `xor ecx, ecx`, the build carries it in r10d and zeroes it twice);
// lead: the three callers may pass a hole index of 0 the link propagated (std::__adjust_heap)
// Round 552C, module dump: the hole's zero is made in the entry for the early exit's phi and again
// before the loop (MachineCSE heuristic #3 refuses the second); the base's entry zero is the
// loop's hole and the early exit has its own in a split edge.
void FUN_009088a0(Heap009088a0 *heap, HeapNode009088a0 *node)
{
    int hole = 0;
    for (int child = 1; child < heap->count; child = 2 * hole + 1) {
        if (child + 1 < heap->count && heap->nodes[child]->cost > heap->nodes[child + 1]->cost)
            ++child;
        heap->nodes[hole] = heap->nodes[child];
        hole = child;
    }
    while (hole > 0) {
        int parent = (hole - 1) / 2;
        if (!(heap->nodes[parent]->cost > node->cost))
            break;
        heap->nodes[hole] = heap->nodes[parent];
        hole = parent;
    }
    heap->nodes[hole] = node;
}
