/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

extern Type00503fb0 *D_5939080; /* derived name: the scene node's type */

/* the child taken out of the node under the world's write lock: the child
 * is read before the lock is taken (`mov r15, [r14+0x68]` before `call
 * 0xd8f040`) */
static inline void removeLocked(Object016b85e0 *node, Object016b9108 *child) /* derived name */
{
    D_5938c40->world->lockWrite();
    node->removeChild(child);
    D_5938c40->world->unlockWrite();
}

/* derived names: the class whose vtable is at 0x16b6a28
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b55320
 * and its complete destructor FUN_00b554d0), over the root class (slots 3
 * and 4 the root's empty bodies): six names from +0x48 (+0x54 not one), a
 * counted reference at +0x68 set by compare-and-swap and an int at +0x38.
 * The destructor, while the int is set: the scene node the name at +0x50
 * names (when it has one) gives the object at +0x68 up as its child under
 * the world's write lock, the reference is emptied by compare-and-swap and
 * the int cleared; then the members are released and the root's destructor
 * inlined. FUN_00b558f0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable; the other slots are
 * not traced. */
class Object016b6a28 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b6a28();

  private:
    u8 unknown24[0x14];
    int unknown38; /* +0x38 */
    u8 unknown3c[0xc];
    Name unknown48; /* +0x48 */
    Name unknown4c; /* +0x4c */
    Name node50;    /* +0x50: the scene node's name */
    u8 unknown54[4];
    Name unknown58;                            /* +0x58 */
    Name unknown5c;                            /* +0x5c */
    Name unknown60;                            /* +0x60 */
    AtomicRef0045c470<Object016b9108> child68; /* +0x68 */
};

Object016b6a28::~Object016b6a28()
{
    if (unknown38 != 0) {
        if (node50.index != 0) {
            Object016b85e0 *node = findNamed<Object016b85e0>(node50, D_5939080);
            if (node)
                removeLocked(node, child68.get());
        }
        child68.clear();
        unknown38 = 0;
    }
}
