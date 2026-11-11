/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16c0478 (config/vtables.derived.base.txt, two slots; stored by its
 * constructor FUN_00fe2710): it deletes every node of the list at +0x78 (each
 * node's next at +0x8 read before the node's deleting destructor, slot 1)
 * and clears the head, then deletes the object at +0x70 and clears the
 * pointer. FUN_00fec000, slot 1, is the deleting one (the last store dead before
 * operator delete). The class has no base. The destructor is the class's key
 * function, so this file emits the vtable. The other members are not traced. */
class Node00febfa0 /* derived name */
{
  public:
    virtual ~Node00febfa0();

    Node00febfa0 *next8; /* +0x8 */
};

class Owned00febfa0 /* derived name */
{
  public:
    virtual ~Owned00febfa0();
};

class Object016c0478 /* derived name */
{
  public:
    virtual ~Object016c0478();

  private:
    u8 unknown8[0x68];
    Owned00febfa0 *owned70; /* +0x70 */
    Node00febfa0 *list78;   /* +0x78 */
};

Object016c0478::~Object016c0478()
{
    for (Node00febfa0 *node = list78; node != 0;) {
        Node00febfa0 *next = node->next8;
        delete node;
        node = next;
    }
    list78 = 0;
    if (owned70 != 0) {
        delete owned70;
        owned70 = 0;
    }
}
