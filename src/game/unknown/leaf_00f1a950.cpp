/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16bedd8
 * (config/vtables.derived.base.txt, stored by FUN_00f1a6c0 FUN_00f1a950),
 * derived from Object00c1b7f0. Its own fields are traced only where its
 * destructor FUN_00f1a950 and the function that enters an object of this
 * layout in its owner's array (FUN_00fc5680, 0xfc5781 to 0xfc5877) use
 * them; the rest are not traced. */
class Object016bedd8 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016bedd8();

  private:
    Object013cd320 part40; /* +0x40 */
    /* +0x1b8: the owner, a counted reference set by compare-and-swap
     * (0xfc5877) */
    AtomicRef0045c470<Node00503fb0> owner;
    Name name1c0; /* +0x1c0: released by the destructor */
    u8 unknown1c4[0x14];
    Registry00f516f0 *registry; /* +0x1d8: the owner's array this object is entered in, or null */
    void *unknown1e0;           /* +0x1e0: set with the array (0xfc578f) */
    /* +0x1e8: a counted reference set by compare-and-swap (0xfc57a7) */
    AtomicRef0045c470<Node00503fb0> held1e8;
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in and empties the reference at +0x1e8 by
 * compare-and-swap; then the members are released, last first, and the
 * base's destructor FUN_00c1b7f0 runs as a tail call. FUN_00f1abf0, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. */
Object016bedd8::~Object016bedd8()
{
    if (registry)
        registry->remove(this);
    held1e8.clear();
}
