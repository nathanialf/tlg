/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object01439e30.h"

/* derived names: the class whose vtable is at 0x16c3580
 * (config/vtables.derived.base.txt, stored by FUN_012e12b0 FUN_012e1d00),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_012e1d00 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the two parts at +0x740 go first of the members, the second before the first, then the part at +0x240. */
class Object016c3580 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c3580();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x30];
    Name name1f0; /* +0x1f0: released by the destructor */
    u8 unknown1f4[0xc];
    int active200; /* +0x200: cleared by the destructor where it is set */
    u8 unknown204[0x4];
    Registry00f516f0 *registry; /* +0x208: the array this object is entered in, or null */
    void *unknown210;           /* +0x210: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x218: a counted reference */
    u8 unknown220[0x20];
    Object016d7d90 part240; /* +0x240: a member whose destructor is held inlined */
    Object016d7de8 parts740
        [2]; /* +0x740: two members destroyed by FUN_01491e40, the second first (`lea rbx, [r14+0x740]` before the first call) */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x200 and empties the reference at +0x218;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_012e2040, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c3580::~Object016c3580()
{
    if (registry)
        registry->remove(this);
    if (active200 != 0)
        active200 = 0;
    held.clear();
}
