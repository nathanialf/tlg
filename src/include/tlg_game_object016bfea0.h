/* src/include/tlg_game_object016bfea0.h: the class whose vtable is at
 * 0x016bfea0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BFEA0_H
#define TLG_GAME_OBJECT016BFEA0_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013d35e0.h"

/* derived names: the class whose vtable is at 0x16bfea0
 * (config/vtables.derived.base.txt, stored by FUN_00f96270 FUN_00f96800),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00f96800 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the pool of the part at +0x2f0 is given up and the object at +0x2e8 released while the int at +0x268 is set; the block at +0xbf0, the part at +0x2f0, the block at +0x2d0 and the array at +0x2a8 go first of the members. */
class Object016bfea0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016bfea0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    u8 unknown1c0[0x98];
    Name name258; /* +0x258: released by the destructor */
    u8 unknown25c[0xc];
    int active268; /* +0x268: cleared by the destructor where it is set */
    u8 unknown26c[0x4];
    Registry00f516f0 *registry; /* +0x270: the array this object is entered in, or null */
    void *unknown278;           /* +0x278: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x280: a counted reference */
    u8 unknown288[0x20];
    Array05943280<Element0101ece0> array2a8; /* +0x2a8: an array of named elements */
    u8 unknown2c0[0x10];
    OwnedBlock05943280 block2d0; /* +0x2d0: a block released by the destructor */
    u8 unknown2d8[0x10];
    Released0101ece0
        *object2e8; /* +0x2e8: released through its slot 3 while the object is active */
    Object013dc6c0
        part2f0; /* +0x2f0: a member destroyed by FUN_013dc6c0; its pool is given up while the object is active */
    u8 unknownbe0[0x10];
    OwnedBlock05943280 blockbf0; /* +0xbf0: a block released by the destructor */
};

#endif
