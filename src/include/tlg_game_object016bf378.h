/* src/include/tlg_game_object016bf378.h: the class whose vtable is at
 * 0x016bf378 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BF378_H
#define TLG_GAME_OBJECT016BF378_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013d35e0.h"

/* derived names: the class whose vtable is at 0x16bf378
 * (config/vtables.derived.base.txt, stored by FUN_00f58fd0 FUN_00f59820),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00f59820 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the object at +0x338 is released while the int at +0x2b4 is set; the part at +0x690, six blocks from +0x678, the part at +0x390, the block at +0x320 and the array at +0x2f8 go first of the members, the block at +0x1c0 after the Name. */
class Object016bf378 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016bf378();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    OwnedBlock05943280 block1c0; /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0xdc];
    Name name2a4; /* +0x2a4: released by the destructor */
    u8 unknown2a8[0xc];
    int active2b4; /* +0x2b4: cleared by the destructor where it is set */
    u8 unknown2b8[0x8];
    Registry00f516f0 *registry; /* +0x2c0: the array this object is entered in, or null */
    void *unknown2c8;           /* +0x2c8: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x2d0: a counted reference */
    u8 unknown2d8[0x20];
    Array05943280<Element0101ece0> array2f8; /* +0x2f8: an array of named elements */
    u8 unknown310[0x10];
    OwnedBlock05943280 block320; /* +0x320: a block released by the destructor */
    u8 unknown328[0x10];
    Released0101ece0
        *object338; /* +0x338: released through its slot 3 while the object is active */
    u8 unknown340[0x50];
    Object016d39f0 part390; /* +0x390: a member destroyed by FUN_013d3970 */
    u8 unknown500[0xf8];
    OwnedBlock05943280 block5f8; /* +0x5f8: a block released by the destructor */
    u8 unknown600[0x10];
    OwnedBlock05943280 block610; /* +0x610: a block released by the destructor */
    u8 unknown618[0x10];
    OwnedBlock05943280 block628; /* +0x628: a block released by the destructor */
    u8 unknown630[0x18];
    OwnedBlock05943280 block648; /* +0x648: a block released by the destructor */
    u8 unknown650[0x10];
    OwnedBlock05943280 block660; /* +0x660: a block released by the destructor */
    u8 unknown668[0x10];
    OwnedBlock05943280 block678; /* +0x678: a block released by the destructor */
    u8 unknown680[0x10];
    Object013d35e0 part690; /* +0x690: a member destroyed by FUN_013d35e0 */
};

#endif
