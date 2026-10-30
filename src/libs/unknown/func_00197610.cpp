/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A leaf counts one; an inner node's count is its children's, its box the
 * first child's grown by the second's. */
// NONMATCHING: equal but for the leaf's return: the base keeps `mov eax, 1; jmp` in a block of
// its own on the leaf edge (`jne body` first), this compile sets eax before the compare and
// jumps to the shared epilogue (`je`), one byte shorter (NOTES Round 63B).
int ElementPool00198a20::FUN_00197610(Element *node)
{
    if (node->children[1] == Element::NO_CHILD) {
        return 1;
    }
    Element *const nodes = elements.data;
    Element &a = nodes[node->children[0]];
    Element &b = nodes[node->children[1]];
    node->numLeaves = FUN_00197610(&a) + FUN_00197610(&b);
    node->aabb = a.aabb;
    for (int i = 0; i < 3; i++) {
        node->aabb.max[i] = hkMath::max2(node->aabb.max[i], b.aabb.max[i]);
    }
    for (int i = 0; i < 3; i++) {
        node->aabb.min[i] = hkMath::min2(node->aabb.min[i], b.aabb.min[i]);
    }
    return node->numLeaves;
}
