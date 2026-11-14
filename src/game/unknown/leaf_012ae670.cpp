/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c3300
 * (config/vtables.derived.base.txt, stored by FUN_012ae3a0 FUN_012ae670),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_012ae670 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the array at +0x258 is emptied while the int at +0x1d0 is set, and its block released first of the members. */
class Object016c3300 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c3300();

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
    u8 unknown1f0[0x68];
    Array05943280<int>
        array258; /* +0x258: an array emptied by the destructor while the object is active */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1d0 and empties the reference at +0x1e8;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_012ae9e0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c3300::~Object016c3300()
{
    if (registry)
        registry->remove(this);
    if (active1d0 != 0) {
        array258.clear();
        active1d0 = 0;
    }
    held.clear();
}
