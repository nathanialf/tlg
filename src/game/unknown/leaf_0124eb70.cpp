/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object00fe9c50.h"

/* derived names: the class whose vtable is at 0x16c25a0
 * (config/vtables.derived.base.txt, stored by FUN_0124e7e0 FUN_0124eb70),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_0124eb70 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the object at +0x2c8 is given up by FUN_01256320 and deleted, then the objects at +0x2b8 and +0x2c0 are released, while the int at +0x234 is set; the block at +0x2a0 and the array at +0x278 go first of the members, the Names at +0x1e0 and +0x1dc and the block at +0x1c0 after the Name at +0x224. */
class Object016c25a0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c25a0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    OwnedBlock05943280 block1c0;           /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x14];
    Name name1dc; /* +0x1dc: released by the destructor */
    Name name1e0; /* +0x1e0: released by the destructor */
    u8 unknown1e4[0x40];
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
    Object01256320
        *object2c8; /* +0x2c8: given up by FUN_01256320 and deleted while the object is active */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x234 and empties the reference at +0x250;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_0124f060, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c25a0::~Object016c25a0()
{
    if (registry)
        registry->remove(this);
    if (active234 != 0) {
        FUN_01256320(object2c8);
        delete object2c8;
        object2c8 = 0;
        if (object2b8)
            object2b8->release();
        object2b8 = 0;
        if (object2c0)
            object2c0->release();
        object2c0 = 0;
        active234 = 0;
    }
    held.clear();
}
