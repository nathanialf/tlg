/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: what the array at +0x238 points to: the destructor
 * (inlined four times in FUN_011b22a0, 0x11b2370) releases the block at
 * +0x190, then deletes the array made with new[] at +0x30 (`mov rdi,
 * [rbx+0x30]; test rdi, rdi; je; call 0x14b03a8`): the member at +0x30
 * deletes it in its own destructor, after the later member's. The rest is
 * not traced. */
struct Buffer011b22a0 { /* derived name */

    ~Buffer011b22a0()
    {
        delete[] data;
    }

    u8 *data;
};

struct Item011b22a0 { /* derived name */
    u8 unknown0[0x30];
    Buffer011b22a0 buffer30; /* +0x30 */
    u8 unknown38[0x158];
    OwnedBlock05943280 block190; /* +0x190 */
};

/* derived names: the class whose vtable is at 0x16c19c8
 * (config/vtables.derived.base.txt, stored by FUN_011b1f50 FUN_011b22a0),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_011b22a0 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the first four objects of the array at +0x238 are deleted while the int at +0x1f8 is set. */
class Object016c19c8 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c19c8();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    u8 unknown1c0[0x8];
    OwnedBlock05943280 block1c8; /* +0x1c8: a block released by the destructor */
    u8 unknown1d0[0x18];
    Name name1e8; /* +0x1e8: released by the destructor */
    u8 unknown1ec[0xc];
    int active1f8; /* +0x1f8: cleared by the destructor where it is set */
    u8 unknown1fc[0x4];
    Registry00f516f0 *registry;           /* +0x200: the array this object is entered in, or null */
    void *unknown208;                     /* +0x208: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x210: a counted reference */
    u8 unknown218[0x20];
    Array05943280<Item011b22a0 *>
        array238; /* +0x238: an array whose first four objects are deleted while the object is active */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1f8 and empties the reference at +0x210;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_011b2770, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c19c8::~Object016c19c8()
{
    if (registry)
        registry->remove(this);
    if (active1f8 != 0) {
        for (int i = 0; i < 4; ++i)
            delete array238[i];
        active1f8 = 0;
    }
    held.clear();
}
