/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16bfd90
 * (config/vtables.derived.base.txt, stored by FUN_00f86720 FUN_00f86a70),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00f86a70 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the four references from +0x278 are emptied and the objects at +0x220 and +0x228 released while the int at +0x1e0 is set; the reference at +0x2a0, the four from +0x278, the block at +0x258 and the array at +0x230 go first of the members. */
class Object016bfd90 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016bfd90();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x10];
    Name name1d0; /* +0x1d0: released by the destructor */
    u8 unknown1d4[0xc];
    int active1e0; /* +0x1e0: cleared by the destructor where it is set */
    u8 unknown1e4[0x4];
    Registry00f516f0 *registry;           /* +0x1e8: the array this object is entered in, or null */
    void *unknown1f0;                     /* +0x1f0: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x1f8: a counted reference */
    u8 unknown200[0x20];
    Released0101ece0
        *object220; /* +0x220: released through its slot 3 while the object is active */
    Released0101ece0
        *object228; /* +0x228: released through its slot 3 while the object is active */
    Array05943280<Element0101ece0> array230; /* +0x230: an array of named elements */
    u8 unknown248[0x10];
    OwnedBlock05943280 block258; /* +0x258: a block released by the destructor */
    u8 unknown260[0x18];
    AtomicRef0045c470<Node00503fb0>
        refs278[4]; /* +0x278: four counted references emptied while the object is active */
    u8 unknown298[0x8];
    AtomicRef0045c470<Node00503fb0> ref2a0; /* +0x2a0: a counted reference */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1e0 and empties the reference at +0x2a0;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00f871b0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: the register assignment differs from the start (`this` in rsi, the base's
// in r13; 1911 bytes for 1841). The deleting destructor is equal and claimed
Object016bfd90::~Object016bfd90()
{
    if (registry)
        registry->remove(this);
    if (active1e0 != 0) {
        for (int i = 0; i < 4; ++i)
            refs278[i].clear();
        if (object220)
            object220->release();
        object220 = 0;
        if (object228)
            object228->release();
        object228 = 0;
        active1e0 = 0;
    }
    held.clear();
}
