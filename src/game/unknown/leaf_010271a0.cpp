/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c0e28
 * (config/vtables.derived.base.txt, stored by FUN_010267b0 FUN_010271a0),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_010271a0 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * eleven blocks are released: the eight from +0x360 first of the members, the three from +0x1c8 after the Name. */
class Object016c0e28 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c0e28();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x8];
    OwnedBlock05943280 block1c8; /* +0x1c8: a block released by the destructor */
    u8 unknown1d0[0x10];
    OwnedBlock05943280 block1e0; /* +0x1e0: a block released by the destructor */
    u8 unknown1e8[0x10];
    OwnedBlock05943280 block1f8; /* +0x1f8: a block released by the destructor */
    u8 unknown200[0x2c];
    Name name22c; /* +0x22c: released by the destructor */
    u8 unknown230[0xc];
    int active23c; /* +0x23c: cleared by the destructor where it is set */
    u8 unknown240[0x8];
    Registry00f516f0 *registry; /* +0x248: the array this object is entered in, or null */
    void *unknown250;           /* +0x250: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x258: a counted reference */
    u8 unknown260[0x100];
    OwnedBlock05943280 block360; /* +0x360: a block released by the destructor */
    u8 unknown368[0x10];
    OwnedBlock05943280 block378; /* +0x378: a block released by the destructor */
    u8 unknown380[0x10];
    OwnedBlock05943280 block390; /* +0x390: a block released by the destructor */
    u8 unknown398[0x78];
    OwnedBlock05943280 block410; /* +0x410: a block released by the destructor */
    u8 unknown418[0x10];
    OwnedBlock05943280 block428; /* +0x428: a block released by the destructor */
    u8 unknown430[0x10];
    OwnedBlock05943280 block440; /* +0x440: a block released by the destructor */
    u8 unknown448[0x10];
    OwnedBlock05943280 block458; /* +0x458: a block released by the destructor */
    u8 unknown460[0x10];
    OwnedBlock05943280 block470; /* +0x470: a block released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x23c and empties the reference at +0x258;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_01027720, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c0e28::~Object016c0e28()
{
    if (registry)
        registry->remove(this);
    if (active23c != 0)
        active23c = 0;
    held.clear();
}
