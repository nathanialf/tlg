/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object011f7800.h"

/* derived names: the class whose vtable is at 0x16beeb0
 * (config/vtables.derived.base.txt, stored by FUN_00f2b8b0 FUN_00f2bd20),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00f2bd20 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * while the int at +0x220 is set the objects at +0x2f8 and +0x2f0 are released, the entries' objects of the array at +0x290 deleted and the array emptied, and the four references from +0x268 emptied; the blocks from +0x338, the block at +0x2d8, the arrays at +0x2b0 and +0x290 and the four references go first of the members. */
class Object016beeb0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016beeb0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x50];
    Name name210; /* +0x210: released by the destructor */
    u8 unknown214[0xc];
    int active220; /* +0x220: cleared by the destructor where it is set */
    u8 unknown224[0x4];
    Registry00f516f0 *registry; /* +0x228: the array this object is entered in, or null */
    void *unknown230;           /* +0x230: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x238: a counted reference */
    u8 unknown240[0x28];
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
    u8 unknown300[0x8];
    OwnedBlock05943280 block308; /* +0x308: a block released by the destructor */
    u8 unknown310[0x10];
    OwnedBlock05943280 block320; /* +0x320: a block released by the destructor */
    u8 unknown328[0x10];
    OwnedBlock05943280 block338; /* +0x338: a block released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x220 and empties the reference at +0x238;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00f2c5b0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: the register assignment differs from the start (`this` in r14, the base's
// in r13; 2193 bytes for 2177). The deleting destructor is equal and claimed
Object016beeb0::~Object016beeb0()
{
    if (registry)
        registry->remove(this);
    if (active220 != 0) {
        if (object2f8)
            object2f8->release();
        object2f8 = 0;
        if (object2f0)
            object2f0->release();
        object2f0 = 0;
        for (int i = 0; i < array290.size(); ++i)
            delete array290.at(i).object8;
        array290.clear();
        for (int i = 0; i < 4; ++i) {
            if (Node011f7800 *node = refs268[i].get()) {
                node->unknowna0 = 0;
                refs268[i].clear();
            }
        }
        active220 = 0;
    }
    held.clear();
}
