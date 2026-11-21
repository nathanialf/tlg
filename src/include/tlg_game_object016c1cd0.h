/* src/include/tlg_game_object016c1cd0.h: the class whose vtable is at
 * 0x016c1cd0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C1CD0_H
#define TLG_GAME_OBJECT016C1CD0_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object011f7800.h"

/* derived names: the class whose vtable is at 0x16c1cd0
 * (config/vtables.derived.base.txt, stored by FUN_011f7400 FUN_011f7800),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_011f7800 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * while the int at +0x228 is set the objects at +0x2f8 and +0x2f0 are released, the entries' objects of the array at +0x290 deleted and the array emptied, and the four references from +0x268 emptied; the block at +0x2d8, the arrays at +0x2b0 and +0x290 and the four references go first of the members, the Names at +0x218 and +0x210 last. */
class Object016c1cd0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c1cd0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    u8 unknown1c0[0x50];
    Name name210; /* +0x210: released by the destructor */
    u8 unknown214[0x4];
    Name name218; /* +0x218: released by the destructor */
    u8 unknown21c[0xc];
    int active228; /* +0x228: cleared by the destructor where it is set */
    u8 unknown22c[0x4];
    Registry00f516f0 *registry; /* +0x230: the array this object is entered in, or null */
    void *unknown238;           /* +0x238: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x240: a counted reference */
    u8 unknown248[0x20];
    AtomicRef0045c470<Node011f7800> refs268
        [4]; /* +0x268: four counted references, each node's pointer at +0xa0 cleared and the reference emptied while the object is active */
    u8 unknown288[0x8];
    Array05943280<Entry011f7800>
        array290; /* +0x290: an array whose entries' objects are deleted and which is emptied while the object is active */
    u8 unknown2a8[0x8];
    Array05943280<Element0101ece0> array2b0; /* +0x2b0: an array of named elements */
    u8 unknown2c8[0x10];
    OwnedBlock05943280 block2d8; /* +0x2d8: a block released by the destructor */
    u8 unknown2e0[0x10];
    Released0101ece0
        *object2f0; /* +0x2f0: released through its slot 3 while the object is active */
    Released0101ece0
        *object2f8; /* +0x2f8: released through its slot 3 while the object is active */
};

#endif
