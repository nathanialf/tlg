/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: FUN_01003640 and FUN_0126eb60 (380 bytes each, the same
 * code but for the name) return the first node of a tree, searched from the
 * given one down through its children (+0x40, count +0x48), that has a
 * component of the type D_581b510 points to with bit 1 of its flags (+0x5c)
 * clear, its int at +0x30 non-zero and its name the one at 0x5acf954 (FUN_01003640) or
 * 0x5ad7e78 (FUN_0126eb60); 0 when none has. The components are scanned
 * under the node's reader count (FUN_01331c10, an atomic decrement drops
 * it) as FUN_00503fb0's first lambda scans them. */
extern Type00503fb0 *D_581b510; /* derived name */
extern Name D_5acf954;          /* derived name */
extern Name D_5ad7e78;          /* derived name */

// NONMATCHING: 4/107, 348 bytes against 380 (380 under the rule of
// tools/patches/llvm-3.7.1-tailmerge-01-narrow-atomic-ends-tail.patch, still 4/107). Besides
// FUN_00857df0's drops (leaf_00857df0.cpp; the base keeps them apart, 0x10036c5 `lock dec; jmp`
// and 0x10036d0 `lock dec` falling into `test rax, rax`), this build specialises the first find
// for an index of 0 (`test ecx, ecx` and a search from 0) where the base's two finds are the same
// general search (`cmp r12d, ecx` at 0x1003671, r12 holding both the index 0 and the return's 0),
// and a name that differs goes back to the first find (0x1003769) (round 579D)
Object016b85e0 *FUN_01003640(Object016b85e0 *node) /* derived name */
{
    if (!node)
        return 0;
    unsigned next = 0;
    for (Component00503fb0 *component = node->findComponent(D_581b510, next); component;
         component = node->findComponent(D_581b510, next))
        if (!(component->flags5c & 1) && component->unknown30 != 0 && component->name == D_5acf954)
            return node;
    for (unsigned i = 0; i < node->childCount; ++i)
        if (Object016b85e0 *found = FUN_01003640(node->children[i].get()))
            return found;
    return 0;
}

// NONMATCHING: as FUN_01003640 (0x126ebe5 and 0x126ebf0)
Object016b85e0 *FUN_0126eb60(Object016b85e0 *node) /* derived name */
{
    if (!node)
        return 0;
    unsigned next = 0;
    for (Component00503fb0 *component = node->findComponent(D_581b510, next); component;
         component = node->findComponent(D_581b510, next))
        if (!(component->flags5c & 1) && component->unknown30 != 0 && component->name == D_5ad7e78)
            return node;
    for (unsigned i = 0; i < node->childCount; ++i)
        if (Object016b85e0 *found = FUN_0126eb60(node->children[i].get()))
            return found;
    return 0;
}
