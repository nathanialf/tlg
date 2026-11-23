/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object016d7a28.h"
#include "tlg_game_collection00214e10.h"

/* derived names: the class whose vtable is at 0x16c0ed8
 * (config/vtables.derived.base.txt, stored by FUN_01034670 FUN_010351b0),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_010351b0 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the collections at +0x14b8 and +0x1188, the Name at +0x1180, the parts at +0xe90, +0xd50 and +0xc60, six blocks from +0xc40 and the part at +0x270 go first of the members. */
class Object016c0ed8 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c0ed8();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x5c];
    Name name21c; /* +0x21c: released by the destructor */
    u8 unknown220[0xc];
    int active22c; /* +0x22c: cleared by the destructor where it is set */
    u8 unknown230[0x8];
    Registry00f516f0 *registry; /* +0x238: the array this object is entered in, or null */
    void *unknown240;           /* +0x240: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x248: a counted reference */
    u8 unknown250[0x20];
    Object016d54f8
        part270; /* +0x270: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    OwnedBlock05943280 blocka90; /* +0xa90: a block released by the destructor */
    u8 unknowna98[0xe8];
    OwnedBlock05943280 blockb80; /* +0xb80: a block released by the destructor */
    u8 unknownb88[0x10];
    OwnedBlock05943280 blockb98; /* +0xb98: a block released by the destructor */
    u8 unknownba0[0x50];
    OwnedBlock05943280 blockbf0; /* +0xbf0: a block released by the destructor */
    u8 unknownbf8[0x10];
    OwnedBlock05943280 blockc08; /* +0xc08: a block released by the destructor */
    u8 unknownc10[0x30];
    OwnedBlock05943280 blockc40; /* +0xc40: a block released by the destructor */
    u8 unknownc48[0x18];
    Object016d54c0
        partc60; /* +0xc60: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknownd10[0x40];
    Object016d5498
        partd50; /* +0xd50: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknowndf0[0xa0];
    Object016d5498
        parte90; /* +0xe90: a member whose destructor is inlined (tlg_game_object016d7a28.h) */
    u8 unknownf30[0x250];
    Name name1180; /* +0x1180: released by the destructor */
    u8 unknown1184[0x4];
    Collection012ec7e0 collection1188; /* +0x1188: emptied by its destructor */
    Collection012ec7e0 collection14b8; /* +0x14b8: emptied by its destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x22c and empties the reference at +0x248;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_01035b80, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c0ed8::~Object016c0ed8()
{
    if (registry)
        registry->remove(this);
    if (active22c != 0)
        active22c = 0;
    held.clear();
}
