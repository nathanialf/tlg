/* src/include/tlg_game_object016c2098.h: the class whose vtable is at
 * 0x016c2098 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C2098_H
#define TLG_GAME_OBJECT016C2098_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013d35e0.h"

/* derived names: the class whose vtable is at 0x16c2098
 * (config/vtables.derived.base.txt, stored by FUN_01215b10 FUN_01216120),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_01216120 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the object at +0x2f8 is released while the int at +0x274 is set; the parts at +0x540 and +0x340, the block at +0x2e0 and the array at +0x2b8 go first of the members, the block at +0x1c0 after the Name. */
class Object016c2098 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c2098();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    OwnedBlock05943280 block1c0; /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x9c];
    Name name264; /* +0x264: released by the destructor */
    u8 unknown268[0xc];
    int active274; /* +0x274: cleared by the destructor where it is set */
    u8 unknown278[0x8];
    Registry00f516f0 *registry; /* +0x280: the array this object is entered in, or null */
    void *unknown288;           /* +0x288: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x290: a counted reference */
    u8 unknown298[0x20];
    Array05943280<Element0101ece0> array2b8; /* +0x2b8: an array of named elements */
    u8 unknown2d0[0x10];
    OwnedBlock05943280 block2e0; /* +0x2e0: a block released by the destructor */
    u8 unknown2e8[0x10];
    Released0101ece0
        *object2f8; /* +0x2f8: released through its slot 3 while the object is active */
    u8 unknown300[0x40];
    Object016d6a50 part340; /* +0x340: a member destroyed by FUN_014785c0 */
    u8 unknown4b0[0x90];
    Object013d35e0 part540; /* +0x540: a member destroyed by FUN_013d35e0 */
};

#endif
