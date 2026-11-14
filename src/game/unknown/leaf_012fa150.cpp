/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c3760
 * (config/vtables.derived.base.txt, stored by FUN_012f9ec0 FUN_012fa150),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_012fa150 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * Object016bedd8's layout with an int at +0x1d0 that is cleared where it is set. */
class Object016c3760 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c3760();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    Name name1c0;                          /* +0x1c0: released by the destructor */
    u8 unknown1c4[0xc];
    int active1d0; /* +0x1d0: cleared by the destructor where it is set */
    u8 unknown1d4[0x4];
    Registry00f516f0 *registry;           /* +0x1d8: the array this object is entered in, or null */
    void *unknown1e0;                     /* +0x1e0: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x1e8: a counted reference */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1d0 and empties the reference at +0x1e8;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_012fa410, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c3760::~Object016c3760()
{
    if (registry)
        registry->remove(this);
    if (active1d0 != 0)
        active1d0 = 0;
    held.clear();
}
