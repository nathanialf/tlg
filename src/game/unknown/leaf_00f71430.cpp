/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
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
 * not traced. */
struct Holder00f71430 { /* derived name */
    u8 unknown0[0x8];
    Array05943280<Array05943280<int>> lists8; /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16bfba8
 * (config/vtables.derived.base.txt, stored by FUN_00f70e20 FUN_00f71430),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00f71430 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * while the int at +0x234 is set the objects at +0x2b8 and +0x2c0 are released, FUN_013d6920 is called on the parts at +0x4b0 and +0x590, the object at +0x680 is deleted and the objects of the array at +0x690 deleted and the array emptied; then the members go, last first. */
class Object016bfba8 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016bfba8();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    OwnedBlock05943280 block1c0;           /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x5c];
    Name name224; /* +0x224: released by the destructor */
    u8 unknown228[0xc];
    int active234; /* +0x234: cleared by the destructor where it is set */
    u8 unknown238[0x8];
    Registry00f516f0 *registry;           /* +0x240: the array this object is entered in, or null */
    void *unknown248;                     /* +0x248: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x250: a counted reference */
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
    u8 unknown480[0x30];
    Object013d6ba0
        part4b0; /* +0x4b0: a member destroyed by FUN_013d6ba0; FUN_013d6920 is called on it while the object is active */
    Object013d6ba0
        part590; /* +0x590: a member destroyed by FUN_013d6ba0; FUN_013d6920 is called on it while the object is active */
    u8 unknown670[0x10];
    Owned00f71430 *object680; /* +0x680: deleted while the object is active */
    u8 unknown688[0x8];
    Array05943280<Holder00f71430 *>
        array690; /* +0x690: an array whose objects are deleted and which is emptied while the object is active */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x234 and empties the reference at +0x250;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00f71ba0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: the register assignment differs from the start (`this` in r13, the base's
// in r14; 1857 bytes for 1889). The deleting destructor is equal and claimed
Object016bfba8::~Object016bfba8()
{
    if (registry)
        registry->remove(this);
    if (active234 != 0) {
        if (object2b8)
            object2b8->release();
        object2b8 = 0;
        if (object2c0)
            object2c0->release();
        object2c0 = 0;
        part4b0.FUN_013d6920();
        part590.FUN_013d6920();
        delete object680;
        object680 = 0;
        for (Holder00f71430 *holder : array690)
            delete holder;
        array690.clear();
        active234 = 0;
    }
    held.clear();
}
