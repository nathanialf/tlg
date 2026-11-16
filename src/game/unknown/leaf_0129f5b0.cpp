/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object016d6730.h"

/* derived names: the class whose vtable is at 0x16c3120
 * (config/vtables.derived.base.txt, stored by FUN_0129ea30 FUN_0129f5b0),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_0129f5b0 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the part at +0x2d0 goes first of the members. */
class Object016c3120 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c3120();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x10];
    Name name1d0; /* +0x1d0: released by the destructor */
    u8 unknown1d4[0xc];
    int active1e0; /* +0x1e0: cleared by the destructor where it is set */
    u8 unknown1e4[0x4];
    Registry00f516f0 *registry; /* +0x1e8: the array this object is entered in, or null */
    void *unknown1f0;           /* +0x1f0: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x1f8: a counted reference */
    u8 unknown200[0xd0];
    Member0129f5b0
        part2d0; /* +0x2d0: a member whose destructor is inlined (tlg_game_object016d6730.h) */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1e0 and empties the reference at +0x1f8;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_0129fad0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: as 0x11cf340: Member0129f5b0's vtable stays its own (emitted local) where the
// base stores 0x16d7bd8 for both; Object016d7bd8's key function is not written
Object016c3120::~Object016c3120()
{
    if (registry)
        registry->remove(this);
    if (active1e0 != 0)
        active1e0 = 0;
    held.clear();
}
