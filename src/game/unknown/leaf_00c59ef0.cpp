/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: first itself on the parent at +0x38 when there is one and bit
 * 1 of the byte at +0x24 is clear, then slot 7 of the object, as a tail call;
 * called from 78 sites (the first in FUN_002155f0). The types are not traced.
 * Class and method unknown. */
class Node00c59ef0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

    u8 unknown8[0x1c];
    u8 unknown24;
    u8 unknown25[0x13];
    Node00c59ef0 *parent; /* +0x38 */
};

void FUN_00c59ef0(Node00c59ef0 *node) /* derived name */
{
    if (node->parent && !(node->unknown24 & 2)) {
        FUN_00c59ef0(node->parent);
    }
    node->slot7();
}
