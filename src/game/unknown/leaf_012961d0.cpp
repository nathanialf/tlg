/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c2fc0
 * (config/vtables.derived.base.txt, stored by FUN_01295e60 FUN_012961d0),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_012961d0 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the block at +0x1c0 is released after the Name. */
class Object016c2fc0 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c2fc0();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    OwnedBlock05943280 block1c0;           /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x14];
    Name name1dc; /* +0x1dc: released by the destructor */
    u8 unknown1e0[0xc];
    int active1ec; /* +0x1ec: cleared by the destructor where it is set */
    u8 unknown1f0[0x8];
    Registry00f516f0 *registry;           /* +0x1f8: the array this object is entered in, or null */
    void *unknown200;                     /* +0x200: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x208: a counted reference */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1ec and empties the reference at +0x208;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_012964d0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c2fc0::~Object016c2fc0()
{
    if (registry)
        registry->remove(this);
    if (active1ec != 0)
        active1ec = 0;
    held.clear();
}
