/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the node class of the type the pointer at 0x58208d8 holds,
 * as far as FUN_00951570 uses it: slot 14 of its vtable takes an int (0
 * there). Its other slots are not traced. */
class Object058208d8 : public Object016b85e0 /* derived name */
{
  public:
    virtual void slot10();        /* derived name; not traced */
    virtual void slot11();        /* derived name; not traced */
    virtual void slot12();        /* derived name; not traced */
    virtual void slot13();        /* derived name; not traced */
    virtual void slot14(int arg); /* derived name */
};

extern Type00503fb0 *D_58208d8;

/* derived name: a node's child at a signed index, as Object016b85e0's
 * componentAt reads a component (`movsxd` under the unsigned counter at
 * 0x951594) */
static inline Object016b85e0 *childAt(const Object016b85e0 *node, int index)
{
    return node->children[index].get();
}

/* derived name: walks a scene node's tree, children first (recursively, from
 * the first child), then calls slot 14 with 0 on the node itself when its
 * type is the one the pointer at 0x58208d8 holds or derives from it; a null
 * node is nothing. Called from FUN_0094a290 (0x94a9a5) and itself. */
void FUN_00951570(Object016b85e0 *node) /* derived name */
{
    if (node == 0)
        return;
    for (unsigned i = 0; i < node->childCount; ++i)
        FUN_00951570(childAt(node, i));
    if (node->isKindOf(D_58208d8))
        static_cast<Object058208d8 *>(node)->slot14(0);
}
