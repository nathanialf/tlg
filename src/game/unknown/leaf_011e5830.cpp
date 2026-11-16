/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_sce_kernel.h"

/* derived names: an event flag deleted with its holder (0x11e59ad: `mov
 * rdi, [rbx]; test rdi, rdi; je; call sceKernelDeleteEventFlag`, then the
 * storage) */
struct EventFlag011e5830 { /* derived name */

    ~EventFlag011e5830()
    {
        if (handle)
            sceKernelDeleteEventFlag(handle);
    }

    SceKernelEventFlag handle;
};

/* derived names: what the pointer at +0x220 of the class below leads to:
 * the objects at +0xaf20 and +0xaf30 are deleted and their pointers cleared
 * by the class's destructor while it is active. The rest is not traced. */
struct World011e5830 { /* derived name */
    u8 unknown0[0xaf20];
    Owned00f71430 *ownedaf20; /* +0xaf20 */
    u8 unknownaf28[0x8];
    EventFlag011e5830 *flagaf30; /* +0xaf30 */
};

/* derived names: what the pointer at +0x218 of the class below leads to: the
 * five counted references its pointer at +0x270 leads to are emptied by
 * the class's destructor while it is active, the pointers read again for
 * each (0x11e5a50). The rest is not traced. */
struct RefsOwner011e5830 { /* derived name */
    u8 unknown0[0x270];
    AtomicRef0045c470<Node00503fb0> *refs270; /* +0x270 */
};

/* derived names: the class whose vtable is at 0x16c1b78
 * (config/vtables.derived.base.txt, stored by FUN_011e5520 FUN_011e5830),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_011e5830 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * while the int at +0x1e8 is set the reference at +0x290 is emptied, the objects at +0xaf30 and +0xaf20 of the one at +0x220 deleted and five references the one at +0x218 leads to emptied; the Name at +0x298 and the reference at +0x290 go first of the members. */
class Object016c1b78 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c1b78();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    OwnedBlock05943280 block1c0;           /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x10];
    Name name1d8; /* +0x1d8: released by the destructor */
    u8 unknown1dc[0xc];
    int active1e8; /* +0x1e8: cleared by the destructor where it is set */
    u8 unknown1ec[0x4];
    Registry00f516f0 *registry;           /* +0x1f0: the array this object is entered in, or null */
    void *unknown1f8;                     /* +0x1f8: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x200: a counted reference */
    u8 unknown208[0x10];
    RefsOwner011e5830 *
        owner218; /* +0x218: the object whose five references are emptied while this one is active */
    World011e5830 *world220; /* +0x220: what the object gives up while it is active */
    u8 unknown228[0x68];
    AtomicRef0045c470<Node00503fb0> ref290; /* +0x290: a counted reference */
    Name name298;                           /* +0x298: released by the destructor */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1e8 and empties the reference at +0x290;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_011e5e30, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: 1527 bytes in the base, 1559 here; the first difference is the extent of the
// active branch (the register assignment around the five references' loop: the base keeps `this` in rdi and on the
// stack)
Object016c1b78::~Object016c1b78()
{
    if (registry)
        registry->remove(this);
    if (active1e8 != 0) {
        ref290.clear();
        delete world220->flagaf30;
        world220->flagaf30 = 0;
        delete world220->ownedaf20;
        world220->ownedaf20 = 0;
        for (int i = 0; i < 5; ++i)
            owner218->refs270[i].clear();
        active1e8 = 0;
    }
    held.clear();
}
