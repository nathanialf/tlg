/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object0140c8d0.h"
#include "tlg_sce_kernel.h"

/* derived names: the class whose vtable is at 0x16c1480
 * (config/vtables.derived.base.txt, stored by FUN_010c67c0 FUN_010c7430),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_010c7430 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * while the int at +0x1ec is set the destructor waits, yielding, for the count at 0x5823544 to be zero; the four blocks from +0x3af8 go first of the members, then four times a block and two arrays (0x80 bytes apart from +0x38f8), the four parts and the part at +0x230. */
class Object016c1480 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c1480();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x1c];
    Name name1dc; /* +0x1dc: released by the destructor */
    u8 unknown1e0[0xc];
    int active1ec; /* +0x1ec: cleared by the destructor where it is set */
    u8 unknown1f0[0x8];
    Registry00f516f0 *registry; /* +0x1f8: the array this object is entered in, or null */
    void *unknown200;           /* +0x200: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x208: a counted reference */
    u8 unknown210[0x20];
    Object016d5980 part230;      /* +0x230: a member whose destructor is held inlined */
    Object0140c8d0 parts1370[4]; /* +0x1370: four members destroyed by FUN_0140c8d0, last first */
    u8 unknown38f0[0x8];
    Object01347230 array38f8; /* +0x38f8: an array of 96-byte entries, destroyed by FUN_01347230 */
    Object0134f620
        array3910; /* +0x3910: an array of counted references, destroyed by FUN_0134f620 */
    u8 unknown3928[0x28];
    OwnedBlock05943280 block3950; /* +0x3950: a block released by the destructor */
    u8 unknown3958[0x20];
    Object01347230 array3978; /* +0x3978: an array of 96-byte entries, destroyed by FUN_01347230 */
    Object0134f620
        array3990; /* +0x3990: an array of counted references, destroyed by FUN_0134f620 */
    u8 unknown39a8[0x28];
    OwnedBlock05943280 block39d0; /* +0x39d0: a block released by the destructor */
    u8 unknown39d8[0x20];
    Object01347230 array39f8; /* +0x39f8: an array of 96-byte entries, destroyed by FUN_01347230 */
    Object0134f620
        array3a10; /* +0x3a10: an array of counted references, destroyed by FUN_0134f620 */
    u8 unknown3a28[0x28];
    OwnedBlock05943280 block3a50; /* +0x3a50: a block released by the destructor */
    u8 unknown3a58[0x20];
    Object01347230 array3a78; /* +0x3a78: an array of 96-byte entries, destroyed by FUN_01347230 */
    Object0134f620
        array3a90; /* +0x3a90: an array of counted references, destroyed by FUN_0134f620 */
    u8 unknown3aa8[0x28];
    OwnedBlock05943280 block3ad0; /* +0x3ad0: a block released by the destructor */
    u8 unknown3ad8[0x20];
    OwnedBlock05943280 block3af8; /* +0x3af8: a block released by the destructor */
    u8 unknown3b00[0x18];
    OwnedBlock05943280 block3b18; /* +0x3b18: a block released by the destructor */
    u8 unknown3b20[0x18];
    OwnedBlock05943280 block3b38; /* +0x3b38: a block released by the destructor */
    u8 unknown3b40[0x18];
    OwnedBlock05943280 block3b58; /* +0x3b58: a block released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1ec and empties the reference at +0x208;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_010c79c0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c1480::~Object016c1480()
{
    if (registry)
        registry->remove(this);
    if (active1ec != 0) {
        while (!__sync_bool_compare_and_swap(&D_5823544, 0, 0))
            scePthreadYield();
        active1ec = 0;
    }
    held.clear();
}
