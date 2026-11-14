/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c2ef8
 * (config/vtables.derived.base.txt, stored by FUN_0128ec10 FUN_0128ef90),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_0128ef90 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the object at +0x288 is released while the int at +0x204 is set; the block at +0x270 and the array at +0x248 go first of the members, the block at +0x1c0 after the Name. */
class Object016c2ef8 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c2ef8();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    OwnedBlock05943280 block1c0;           /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x2c];
    Name name1f4; /* +0x1f4: released by the destructor */
    u8 unknown1f8[0xc];
    int active204; /* +0x204: cleared by the destructor where it is set */
    u8 unknown208[0x8];
    Registry00f516f0 *registry;           /* +0x210: the array this object is entered in, or null */
    void *unknown218;                     /* +0x218: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x220: a counted reference */
    u8 unknown228[0x20];
    Array05943280<Element0101ece0> array248; /* +0x248: an array of named elements */
    u8 unknown260[0x10];
    OwnedBlock05943280 block270; /* +0x270: a block released by the destructor */
    u8 unknown278[0x10];
    Released0101ece0
        *object288; /* +0x288: released through its slot 3 while the object is active */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x204 and empties the reference at +0x220;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_0128f3b0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: greedy's register assignment: 7 instructions of the element array's destructor loop, rcx and
// rdx exchanged (base `lea rdx, [rcx+rcx*4]; shl rdx, 5; mov ecx, [r13+rdx]`, build `lea rcx; shl rcx; mov edx,
// [r13+rcx]`), same size
Object016c2ef8::~Object016c2ef8()
{
    if (registry)
        registry->remove(this);
    if (active204 != 0) {
        if (object288)
            object288->release();
        object288 = 0;
        active204 = 0;
    }
    held.clear();
}
