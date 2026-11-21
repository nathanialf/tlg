/* src/include/tlg_game_object016bfba8.h: the class whose vtable is at
 * 0x016bfba8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BFBA8_H
#define TLG_GAME_OBJECT016BFBA8_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object013da160.h"

/* derived names: an object of the array at +0x690 of the class below, each
 * deleted while it is active: an array at +0x8 of 24-byte elements, each
 * an array whose block is released (0xf71610: `mov eax, r12d; lea rax,
 * [rax+rax*2]` and the release of the block at [rcx+rax*8]). The rest is
 * not traced. The inner arrays hold entries of this holder's own kind
 * (an instantiation of its own: the base has its destructor inlined). */
struct Entry00f71430 { /* derived name: nothing of it is traced */
    int unknown0;
};

struct Holder00f71430 { /* derived name */
    u8 unknown0[0x8];
    Array05943280<Array05943280<Entry00f71430>> lists8; /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16bfba8
 * (config/vtables.derived.base.txt, stored by FUN_00f70e20 FUN_00f71430),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00f71430 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * while the int at +0x234 is set the objects at +0x2b8 and +0x2c0 are released, FUN_013d6920 is called on the parts at +0x4b0 and +0x590, the object at +0x680 is deleted and the objects of the array at +0x690 deleted and the array emptied; then the members go, last first. */
class Object016bfba8 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016bfba8();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    OwnedBlock05943280 block1c0; /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x5c];
    Name name224; /* +0x224: released by the destructor */
    u8 unknown228[0xc];
    int active234; /* +0x234: cleared by the destructor where it is set */
    u8 unknown238[0x8];
    Registry00f516f0 *registry; /* +0x240: the array this object is entered in, or null */
    void *unknown248;           /* +0x248: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x250: a counted reference */
    u8 unknown258[0x20];
    Array05943280<Element0101ece0> array278; /* +0x278: an array of named elements */
    u8 unknown290[0x10];
    OwnedBlock05943280 block2a0; /* +0x2a0: a block released by the destructor */
    u8 unknown2a8[0x10];
    Released0101ece0
        *object2b8; /* +0x2b8: released through its slot 3 while the object is active */
    Released0101ece0
        *object2c0; /* +0x2c0: released through its slot 3 while the object is active */
    u8 unknown2c8[0x8];
    OwnedBlock05943280 block2d0; /* +0x2d0: a block released by the destructor */
    u8 unknown2d8[0x80];
    Name name358; /* +0x358: released by the destructor */
    u8 unknown35c[0x104];
    Object013da160 part460; /* +0x460: a member whose destructor is inlined (FUN_013da160) */
    u8 unknown490[0x20];
    /* +0x4b0: two members destroyed by FUN_013d6ba0, an array: destroyed last
     * first with the array's start formed before the first destructor (`lea
     * rdi, [r14+0x590]; lea rbx, [r14+0x4b0]; call 0x13d6ba0` at 0xf71817);
     * FUN_013d6920 is called on each while the object is active */
    Object013d6ba0 parts4b0[2];
    u8 unknown670[0x10];
    Owned00f71430 *object680; /* +0x680: deleted while the object is active */
    u8 unknown688[0x8];
    Array05943280<Holder00f71430 *>
        array690; /* +0x690: an array whose objects are deleted and which is emptied while the object is active */
};

#endif
