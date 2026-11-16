/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object016d6730.h"

/* derived names: the class whose vtable is at 0x16c1ac8
 * (config/vtables.derived.base.txt, stored by FUN_011ce120 FUN_011cf340),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_011cf340 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the part at +0x4a0 goes first of the members. */
class Object016c1ac8 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c1ac8();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x54];
    Name name214; /* +0x214: released by the destructor */
    u8 unknown218[0xc];
    int active224; /* +0x224: cleared by the destructor where it is set */
    u8 unknown228[0x8];
    Registry00f516f0 *registry;           /* +0x230: the array this object is entered in, or null */
    void *unknown238;                     /* +0x238: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x240: a counted reference */
    u8 unknown248[0x258];
    Member011cf340
        part4a0; /* +0x4a0: a member whose destructor is inlined (tlg_game_object016d6730.h) */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x224 and empties the reference at +0x240;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_011cf860, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: the member's two vtable stores take two addresses here (`lea rax` twice:
// Member011cf340's own vtable, emitted local, and Object016d6730's) where the base forms one address in rbx for both:
// the module does not merge the two vtables, because Object016d6730's vtable is not defined in it (its key function,
// slot 0 FUN_01471f40, is not written)
Object016c1ac8::~Object016c1ac8()
{
    if (registry)
        registry->remove(this);
    if (active224 != 0)
        active224 = 0;
    held.clear();
}
