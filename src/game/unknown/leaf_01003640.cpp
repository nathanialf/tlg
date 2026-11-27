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

/* derived name: the next component from `next` on of the type D_581b510
 * points to that is active: bit 1 of its flags (+0x5c) clear and its int at
 * +0x30 non-zero (the test of leaf_004afa60.cpp's isActive); 0 when none is */
static inline Component00503fb0 *findActive(Object016b85e0 *node, unsigned &next) /* derived name */
{
    for (Component00503fb0 *component = node->findComponent(D_581b510, next); component;
         component = node->findComponent(D_581b510, next))
        if (!(component->flags5c & 1) && component->unknown30 != 0)
            return component;
    return 0;
}

/* The name test fails back to the first search of findActive (0x1003769 to 0x100365e), the
 * activity test to its second: the scan is the outer loop around findActive, so the first search
 * takes `next` from the loop and is not specialised for 0. The children's end is formed once
 * (the count at +0x48 read once, a down-counter of its bytes). */
Object016b85e0 *FUN_01003640(Object016b85e0 *node) /* derived name */
{
    if (!node)
        return 0;
    unsigned next = 0;
    while (Component00503fb0 *component = findActive(node, next))
        if (component->name == D_5acf954)
            return node;
    Object016b85e0 *found = 0;
    Ref00503fb0<Object016b85e0> *end = node->children + node->childCount;
    for (Ref00503fb0<Object016b85e0> *child = node->children; child != end; ++child) {
        found = FUN_01003640(child->get());
        if (found)
            break;
    }
    return found;
}

Object016b85e0 *FUN_0126eb60(Object016b85e0 *node) /* derived name */
{
    if (!node)
        return 0;
    unsigned next = 0;
    while (Component00503fb0 *component = findActive(node, next))
        if (component->name == D_5ad7e78)
            return node;
    Object016b85e0 *found = 0;
    Ref00503fb0<Object016b85e0> *end = node->children + node->childCount;
    for (Ref00503fb0<Object016b85e0> *child = node->children; child != end; ++child) {
        found = FUN_0126eb60(child->get());
        if (found)
            break;
    }
    return found;
}
