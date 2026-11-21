/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the records FUN_00c57870 finds in a node for the key at
 * 0x59473c8, one over the reference's class (the new pointer compared
 * first after the exchange); not traced */
struct Record0083c680 : Object016b9108 /* derived name */
{};

extern u64 D_59473c8; /* derived name: the key the records are looked up by */

/* derived name: the next record for the key after the cursor, which it
 * moves on; null after the last */
Record0083c680 *FUN_00c57870(Node00503fb0 *node, u64 key, int *cursor);

/* derived name: every record for the key in the node and its children,
 * depth first, each in turn put in the reference (so the last one stays);
 * the one int is the records' cursor, then the children's index (its
 * address taken: `lea rdx, [rbp-0x34]`, the index read back from it) */
// NONMATCHING: the base keeps the set's null test of the found record (`test rcx, rcx` after
// the exchange) although the loop has just tested it; the build drops it. The rest equal.
void FUN_0083c680(Node00503fb0 *node, AtomicRef0045c470<Object016b9108> *found) /* derived name */
{
    int i = 0;
    while (Record0083c680 *record = FUN_00c57870(node, D_59473c8, &i))
        found->set(record);
    for (i = 0; unsigned(i) < node->childCount; i++)
        FUN_0083c680(node->childAt(i), found);
}
