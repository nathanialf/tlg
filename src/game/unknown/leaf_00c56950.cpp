/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the sum over a tree: slot 7 of the node plus this
 * function on each child of the pointer array at +0x40 (its count at +0x48,
 * both read once, after the call). Called from FUN_002ca480 and many more.
 * The node's class and its slot's meaning are not traced. */
class Node00c56950 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual int slot7();  /* derived name */

    u8 unknown8[0x38];
    Node00c56950 **unknown40; /* +0x40: the children */
    u32 unknown48;            /* +0x48: the count of +0x40 */
};

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: the link never
 * inlines it (cost=never): one signature changes no row) */
int FUN_00c56950(Node00c56950 *node) /* derived name */
{
    int total = node->slot7();
    Node00c56950 **child = node->unknown40;
    Node00c56950 **end = child + node->unknown48;
    for (; child != end; ++child)
        total += FUN_00c56950(*child);
    return total;
}
