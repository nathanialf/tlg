/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c3680
 * (config/vtables.derived.base.txt, stored by FUN_012f5a40 FUN_012f5cd0),
 * derived from Object00c1b7f0. Its destructor FUN_012f5cd0 is FUN_00f1a950
 * (leaf_00f1a950.cpp) instruction for instruction but for the vtable, so
 * the fields that destructor uses are Object016bedd8's, at the same
 * offsets; the rest are not traced. */
class Object016c3680 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c3680();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    Name name1c0;                          /* +0x1c0: released by the destructor */
    u8 unknown1c4[0x14];
    Registry00f516f0 *registry; /* +0x1d8: the array this object is entered in, or null */
    void *unknown1e0;
    AtomicRef0045c470<Node00503fb0> held1e8; /* +0x1e8: a counted reference */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in and empties the reference at +0x1e8; then the
 * members are released, last first, and the base's destructor FUN_00c1b7f0
 * runs as a tail call. FUN_012f5f70, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016c3680::~Object016c3680()
{
    if (registry)
        registry->remove(this);
    held1e8.clear();
}
