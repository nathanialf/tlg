/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object0140ccc0.h"

/* derived names: the 0x70-byte element of the array at +0x3d0: a block at
 * +0x50, released for each element when the array is destroyed (0xfdbfa9:
 * `imul rax, rax, 0x70`, the block read at `[rcx+rax+0x50]`). The rest is
 * not traced. */
struct Element00fdbd90 { /* derived name */
    u8 unknown0[0x50];
    OwnedBlock05943280 block50; /* +0x50 */
    u8 unknown58[0x18];
};

/* derived names: the class whose vtable is at 0x16c02b0
 * (config/vtables.derived.base.txt, stored by FUN_00fdb6d0 FUN_00fdbd90),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00fdbd90 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the part at +0x530 goes first of the members, then the Names at +0x510 and +0x4e0, the array at +0x3d0 and six blocks. */
class Object016c02b0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c02b0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x8];
    Name name1c8; /* +0x1c8: released by the destructor */
    u8 unknown1cc[0xc];
    int active1d8; /* +0x1d8: cleared by the destructor where it is set */
    u8 unknown1dc[0x4];
    Registry00f516f0 *registry; /* +0x1e0: the array this object is entered in, or null */
    void *unknown1e8;           /* +0x1e8: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x1f0: a counted reference */
    u8 unknown1f8[0xa0];
    OwnedBlock05943280 block298; /* +0x298: a block released by the destructor */
    u8 unknown2a0[0x20];
    OwnedBlock05943280 block2c0; /* +0x2c0: a block released by the destructor */
    u8 unknown2c8[0x20];
    OwnedBlock05943280 block2e8; /* +0x2e8: a block released by the destructor */
    u8 unknown2f0[0x20];
    OwnedBlock05943280 block310; /* +0x310: a block released by the destructor */
    u8 unknown318[0x20];
    OwnedBlock05943280 block338; /* +0x338: a block released by the destructor */
    u8 unknown340[0x48];
    OwnedBlock05943280 block388; /* +0x388: a block released by the destructor */
    u8 unknown390[0x40];
    Array05943280<Element00fdbd90>
        array3d0; /* +0x3d0: an array of 0x70-byte elements that each own a block */
    u8 unknown3e8[0xf8];
    Name name4e0; /* +0x4e0: released by the destructor */
    u8 unknown4e4[0x2c];
    Name name510; /* +0x510: released by the destructor */
    u8 unknown514[0x1c];
    Object013e8670 part530; /* +0x530: a member destroyed by FUN_013e8670 */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1d8 and empties the reference at +0x1f0;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00fdc310, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c02b0::~Object016c02b0()
{
    if (registry)
        registry->remove(this);
    if (active1d8 != 0)
        active1d8 = 0;
    held.clear();
}
