/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: FUN_0083c7f0, FUN_0083c9f0 and FUN_0083cc00 (called by
 * FUN_008380b0 at 0x8385ac, 0x8385c5, 0x83945a and 0x839556, each only
 * while the reference it passes is empty) set a counted reference another thread
 * may replace to each component of one type in turn (the type the pointer
 * at 0x58b70f8 holds, the one at 0x598a010 and the one at 0x5946a58), the
 * node's components scanned under its reader count from after the last
 * one found, then do the same for each child, depth first: the last one
 * found is left in the reference. The type is each function's own: the
 * three bodies differ in nothing else. */
extern const Type00503fb0 *D_58b70f8; /* derived name */
extern const Type00503fb0 *D_598a010; /* derived name */
extern const Type00503fb0 *D_5946a58; /* derived name */

// NONMATCHING: the reader count's exits (the class of FUN_00905ee0): the
// base's first search, peeled from the loop, leaves through one `lock dec
// dword [r13+0x30]`, the later ones through `lock dec [r15]`; this build
// spills the count's address before the first call (`mov [rbp-0x30], r15`)
// and keeps the node in r14 where the base has r13: 12/144, 410 bytes
// against 506. The same in FUN_0083c9f0 and FUN_0083cc00.
void FUN_0083c7f0(Node00503fb0 *node,
                  AtomicRef0045c470<Component00503fb0> *found) /* derived name */
{
    unsigned next = 0;
    while (Component00503fb0 *component = node->findComponent(D_58b70f8, next))
        found->set(component);
    for (unsigned i = 0; i < node->childCount; ++i)
        FUN_0083c7f0(node->childAt(i), found);
}

void FUN_0083c9f0(Node00503fb0 *node,
                  AtomicRef0045c470<Component00503fb0> *found) /* derived name */
{
    unsigned next = 0;
    while (Component00503fb0 *component = node->findComponent(D_598a010, next))
        found->set(component);
    for (unsigned i = 0; i < node->childCount; ++i)
        FUN_0083c9f0(node->childAt(i), found);
}

void FUN_0083cc00(Node00503fb0 *node,
                  AtomicRef0045c470<Component00503fb0> *found) /* derived name */
{
    unsigned next = 0;
    while (Component00503fb0 *component = node->findComponent(D_5946a58, next))
        found->set(component);
    for (unsigned i = 0; i < node->childCount; ++i)
        FUN_0083cc00(node->childAt(i), found);
}
