/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object016d7a28.h"

/* derived names: the class whose vtable is at 0x16c0ce0
 * (config/vtables.derived.base.txt, stored by FUN_01016390 FUN_01016ab0),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_01016ab0 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * four blocks from +0x858, the three elements from +0x700, the parts at +0x4c0, +0x380 and +0x2b0 go first of the members. */
class Object016c0ce0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c0ce0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x20];
    Name name1e0; /* +0x1e0: released by the destructor */
    u8 unknown1e4[0xc];
    int active1f0; /* +0x1f0: cleared by the destructor where it is set */
    u8 unknown1f4[0x4];
    Registry00f516f0 *registry;           /* +0x1f8: the array this object is entered in, or null */
    void *unknown200;                     /* +0x200: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x208: a counted reference */
    u8 unknown210[0xa0];
    Object016d52f0
        part2b0; /* +0x2b0: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknown360[0x20];
    Object016d52c8
        part380; /* +0x380: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknown420[0xa0];
    Object016d52c8
        part4c0; /* +0x4c0: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknown560[0x40];
    Element0140ccc0
        element5a0; /* +0x5a0: a reference at +0x98 released by its destructor (tlg_game_object0140ccc0.h) */
    Element0140ccc0
        element650; /* +0x650: a reference at +0x98 released by its destructor (tlg_game_object0140ccc0.h) */
    Element0140ccc0
        element700; /* +0x700: a reference at +0x98 released by its destructor (tlg_game_object0140ccc0.h) */
    u8 unknown7b0[0x20];
    OwnedBlock05943280 block7d0; /* +0x7d0: a block released by the destructor */
    u8 unknown7d8[0x10];
    OwnedBlock05943280 block7e8; /* +0x7e8: a block released by the destructor */
    u8 unknown7f0[0x50];
    OwnedBlock05943280 block840; /* +0x840: a block released by the destructor */
    u8 unknown848[0x10];
    OwnedBlock05943280 block858; /* +0x858: a block released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1f0 and empties the reference at +0x208;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_010174e0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: 2593 bytes in the base, 1467 here: the components' destructors
// (Object016d52c8, Object016d52f0) are called where the base inlines them
Object016c0ce0::~Object016c0ce0()
{
    if (registry)
        registry->remove(this);
    if (active1f0 != 0)
        active1f0 = 0;
    held.clear();
}
