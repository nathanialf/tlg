/* src/include/tlg_game_object016c0f78.h: the class whose vtable is at
 * 0x016c0f78 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C0F78_H
#define TLG_GAME_OBJECT016C0F78_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013d35e0.h"

/* derived names: the class whose vtable is at 0x16c0f78
 * (config/vtables.derived.base.txt, stored by FUN_01047db0 FUN_01048190),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_01048190 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the objects at +0x290 and +0x298 are released and the one at +0x2a0 deleted while the int at +0x20c is set; the block at +0x278 and the array at +0x250 go first of the members, the four Names from +0x1ec after the Name at +0x1fc. */
class Object016c0f78 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c0f78();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    u8 unknown1c0[0x20];
    Name name1e0; /* +0x1e0: released by the destructor */
    Name name1e4; /* +0x1e4: released by the destructor */
    Name name1e8; /* +0x1e8: released by the destructor */
    Name name1ec; /* +0x1ec: released by the destructor */
    u8 unknown1f0[0xc];
    Name name1fc; /* +0x1fc: released by the destructor */
    u8 unknown200[0xc];
    int active20c; /* +0x20c: cleared by the destructor where it is set */
    u8 unknown210[0x8];
    Registry00f516f0 *registry; /* +0x218: the array this object is entered in, or null */
    void *unknown220;           /* +0x220: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x228: a counted reference */
    u8 unknown230[0x20];
    Array05943280<Element0101ece0> array250; /* +0x250: an array of named elements */
    u8 unknown268[0x10];
    OwnedBlock05943280 block278; /* +0x278: a block released by the destructor */
    u8 unknown280[0x10];
    Released0101ece0
        *object290; /* +0x290: released through its slot 3 while the object is active */
    Released0101ece0
        *object298;            /* +0x298: released through its slot 3 while the object is active */
    Object01052d30 *object2a0; /* +0x2a0: deleted while the object is active */
};

#endif
