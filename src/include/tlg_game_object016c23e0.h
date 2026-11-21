/* src/include/tlg_game_object016c23e0.h: the class whose vtable is at
 * 0x016c23e0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C23E0_H
#define TLG_GAME_OBJECT016C23E0_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013d35e0.h"

/* derived names: the class whose vtable is at 0x16c23e0
 * (config/vtables.derived.base.txt, stored by FUN_01227740 FUN_01227c70),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_01227c70 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the pool of the part at +0x2d0 is given up and the object at +0x2c8 released while the int at +0x248 is set; the part at +0x2d0, the block at +0x2b0 and the array at +0x288 go first of the members. */
class Object016c23e0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c23e0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    u8 unknown1c0[0x78];
    Name name238; /* +0x238: released by the destructor */
    u8 unknown23c[0xc];
    int active248; /* +0x248: cleared by the destructor where it is set */
    u8 unknown24c[0x4];
    Registry00f516f0 *registry; /* +0x250: the array this object is entered in, or null */
    void *unknown258;           /* +0x258: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x260: a counted reference */
    u8 unknown268[0x20];
    Array05943280<Element0101ece0> array288; /* +0x288: an array of named elements */
    u8 unknown2a0[0x10];
    OwnedBlock05943280 block2b0; /* +0x2b0: a block released by the destructor */
    u8 unknown2b8[0x10];
    Released0101ece0
        *object2c8; /* +0x2c8: released through its slot 3 while the object is active */
    Object0147a620
        part2d0; /* +0x2d0: a member destroyed by FUN_0147a620; its pool is given up while the object is active */
};

#endif
