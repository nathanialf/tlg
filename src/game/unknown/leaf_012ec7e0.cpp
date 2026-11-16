/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object016d7eb0.h"
#include "tlg_game_collection00214e10.h"

/* derived names: the class whose vtable is at 0x16c3600
 * (config/vtables.derived.base.txt, stored by FUN_012ec160 FUN_012ec7e0),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_012ec7e0 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the blocks from +0x13c0 and the Name at +0x132c, four blocks from +0x1310, four collections from +0xf68, the block at +0x520 and the parts at +0x390 and +0x220 go first of the members. */
class Object016c3600 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c3600();

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
    u8 unknown1f0[0x30];
    Object016d7e68
        part220; /* +0x220: a member whose destructor is inlined (tlg_game_object016d7eb0.h) */
    Object016d7e68
        part390; /* +0x390: a member whose destructor is inlined (tlg_game_object016d7eb0.h) */
    u8 unknown500[0x20];
    OwnedBlock05943280 block520; /* +0x520: a block released by the destructor */
    u8 unknown528[0xb0];
    Collection012ec7e0 collection5d8; /* +0x5d8: emptied by its destructor */
    Collection012ec7e0 collection908; /* +0x908: emptied by its destructor */
    Collection012ec7e0 collectionc38; /* +0xc38: emptied by its destructor */
    Collection012ec7e0 collectionf68; /* +0xf68: emptied by its destructor */
    u8 unknown1298[0x8];
    OwnedBlock05943280 block12a0; /* +0x12a0: a block released by the destructor */
    u8 unknown12a8[0x38];
    OwnedBlock05943280 block12e0; /* +0x12e0: a block released by the destructor */
    u8 unknown12e8[0x10];
    OwnedBlock05943280 block12f8; /* +0x12f8: a block released by the destructor */
    u8 unknown1300[0x10];
    OwnedBlock05943280 block1310; /* +0x1310: a block released by the destructor */
    u8 unknown1318[0x14];
    Name name132c; /* +0x132c: released by the destructor */
    u8 unknown1330[0x78];
    OwnedBlock05943280 block13a8; /* +0x13a8: a block released by the destructor */
    u8 unknown13b0[0x10];
    OwnedBlock05943280 block13c0; /* +0x13c0: a block released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1d0 and empties the reference at +0x1e8;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_012ed240, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: 2641 bytes in the base, 1563 here: the components' and collections'
// destructors are called where the base inlines them
Object016c3600::~Object016c3600()
{
    if (registry)
        registry->remove(this);
    if (active1d0 != 0)
        active1d0 = 0;
    held.clear();
}
