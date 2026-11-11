/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16c2620 (config/vtables.derived.base.txt, two slots; stored by its
 * constructor FUN_0124f080): it deletes every node of the list at +0x78 (each
 * node's next at +0x8 read before the node's deleting destructor, slot 1)
 * and clears the head, then deletes the object at +0x70 and clears the
 * pointer. FUN_012586d0, slot 1, is the deleting one (the last store dead before
 * operator delete). The class has no base. The destructor is the class's key
 * function, so this file emits the vtable. The other members are not traced. */
class Node01258670 /* derived name */
{
  public:
    virtual ~Node01258670();

    Node01258670 *next8; /* +0x8 */
};

class Owned01258670 /* derived name */
{
  public:
    virtual ~Owned01258670();
};

class Object016c2620 /* derived name */
{
  public:
    virtual ~Object016c2620();

  private:
    u8 unknown8[0x68];
    Owned01258670 *owned70; /* +0x70 */
    Node01258670 *list78;   /* +0x78 */
};

Object016c2620::~Object016c2620()
{
    for (Node01258670 *node = list78; node != 0;) {
        Node01258670 *next = node->next8;
        delete node;
        node = next;
    }
    list78 = 0;
    if (owned70 != 0) {
        delete owned70;
        owned70 = 0;
    }
}
