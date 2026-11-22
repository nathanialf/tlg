/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: FUN_00905ee0 and FUN_009060e0 (called by FUN_00903c90
 * at 0x904179 and 0x90447b, each with an empty array on its frame)
 * gather, depth first from a node, each node's first component of one type
 * (the type the pointer at 0x581b798 holds, and the one at 0x5948180) into
 * the array: the node's components scanned under its reader count, then
 * each child under a reference of its own. The children's array is read
 * once (its end formed before the first call); a null node adds nothing,
 * but its children are read all the same. The type is each function's own:
 * the two bodies differ in nothing else. */
extern const Type00503fb0 *D_581b798; /* derived name */
extern Type00503fb0 *D_5948180;       /* derived name */

// NONMATCHING: the reader count's exits: the base leaves the component search
// through one `lock dec dword [r14+0x30]` block (its address formed again
// after `lea rdi, [r14+0x30]` for FUN_01331c10) with the found component
// tested after it; this build keeps the address in r15 and threads the null
// result through a decrement of its own on each exit (the brief's class of
// the count's address formed twice); 17/140, 492 bytes against 508. The
// same in FUN_009060e0.
void FUN_00905ee0(Array05943280<Component00503fb0 *> *found,
                  Object016b85e0 *node) /* derived name */
{
    if (node) {
        if (Component00503fb0 *component = node->findComponent(D_581b798))
            found->push(component);
    }
    for (Ref00503fb0<Object016b85e0> *child = node->children, *end = child + node->childCount;
         child != end; ++child) {
        Ref00503fb0<Object016b85e0> held(*child);
        FUN_00905ee0(found, held.get());
    }
}

void FUN_009060e0(Array05943280<Component00503fb0 *> *found,
                  Object016b85e0 *node) /* derived name */
{
    if (node) {
        if (Component00503fb0 *component = node->findComponent(D_5948180))
            found->push(component);
    }
    for (Ref00503fb0<Object016b85e0> *child = node->children, *end = child + node->childCount;
         child != end; ++child) {
        Ref00503fb0<Object016b85e0> held(*child);
        FUN_009060e0(found, held.get());
    }
}
