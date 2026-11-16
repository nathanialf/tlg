/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object016d7a28.h"

/* derived names: the class whose vtable is at 0x16c2e58
 * (config/vtables.derived.base.txt, stored by FUN_01280e30 FUN_01281820),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_01281820 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the blocks at +0xfc8 and +0xfb0, the parts at +0xe70, +0xd30 and +0xc40, six blocks from +0xc20 and the part at +0x250 go first of the members. */
class Object016c2e58 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c2e58();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x34];
    Name name1f4; /* +0x1f4: released by the destructor */
    u8 unknown1f8[0xc];
    int active204; /* +0x204: cleared by the destructor where it is set */
    u8 unknown208[0x8];
    Registry00f516f0 *registry;           /* +0x210: the array this object is entered in, or null */
    void *unknown218;                     /* +0x218: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x220: a counted reference */
    u8 unknown228[0x28];
    Object016d7a88
        part250; /* +0x250: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    OwnedBlock05943280 blocka70; /* +0xa70: a block released by the destructor */
    u8 unknowna78[0xe8];
    OwnedBlock05943280 blockb60; /* +0xb60: a block released by the destructor */
    u8 unknownb68[0x10];
    OwnedBlock05943280 blockb78; /* +0xb78: a block released by the destructor */
    u8 unknownb80[0x50];
    OwnedBlock05943280 blockbd0; /* +0xbd0: a block released by the destructor */
    u8 unknownbd8[0x10];
    OwnedBlock05943280 blockbe8; /* +0xbe8: a block released by the destructor */
    u8 unknownbf0[0x30];
    OwnedBlock05943280 blockc20; /* +0xc20: a block released by the destructor */
    u8 unknownc28[0x18];
    Object016d7a50
        partc40; /* +0xc40: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknowncf0[0x40];
    Object016d7a28
        partd30; /* +0xd30: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknowndd0[0xa0];
    Object016d7a28
        parte70; /* +0xe70: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknownf10[0xa0];
    OwnedBlock05943280 blockfb0; /* +0xfb0: a block released by the destructor */
    u8 unknownfb8[0x10];
    OwnedBlock05943280 blockfc8; /* +0xfc8: a block released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x204 and empties the reference at +0x220;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_012821f0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: 2497 bytes in the base, 1371 here: the components' destructors are called
// where the base inlines them
Object016c2e58::~Object016c2e58()
{
    if (registry)
        registry->remove(this);
    if (active204 != 0)
        active204 = 0;
    held.clear();
}
