/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c2520
 * (config/vtables.derived.base.txt, stored by FUN_0124bff0 FUN_0124c400),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_0124c400 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the Names at +0x2d0 and +0x2a0 are released first. */
class Object016c2520 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c2520();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x4];
    Name name1c4; /* +0x1c4: released by the destructor */
    u8 unknown1c8[0xc];
    int active1d4; /* +0x1d4: cleared by the destructor where it is set */
    u8 unknown1d8[0x8];
    Registry00f516f0 *registry;           /* +0x1e0: the array this object is entered in, or null */
    void *unknown1e8;                     /* +0x1e8: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x1f0: a counted reference */
    u8 unknown1f8[0xa8];
    Name name2a0; /* +0x2a0: released by the destructor */
    u8 unknown2a4[0x2c];
    Name name2d0; /* +0x2d0: released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1d4 and empties the reference at +0x1f0;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_0124c740, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c2520::~Object016c2520()
{
    if (registry)
        registry->remove(this);
    if (active1d4 != 0)
        active1d4 = 0;
    held.clear();
}
