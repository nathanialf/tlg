/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_object013ef2e0.h"

/* derived names: what the pointer at +0x220 of the class below leads to: an
 * object whose pointer at +0x28 holds three counted references at +0x28,
 * +0x30 and +0x38, emptied in that order by the class's destructor while
 * it is active, behind a test of that pointer (0x10061f1: `mov rax,
 * [r14+0x220]; mov r15, [rax+0x28]; test r15, r15`). The rest is not
 * traced. */
struct Refs01006120 { /* derived name */
    u8 unknown0[0x28];
    AtomicRef0045c470<Node00503fb0> ref28; /* +0x28 */
    AtomicRef0045c470<Node00503fb0> ref30; /* +0x30 */
    AtomicRef0045c470<Node00503fb0> ref38; /* +0x38 */
};

struct Owner01006120 { /* derived name */
    u8 unknown0[0x28];
    Refs01006120 *refs28; /* +0x28 */
};

/* derived names: the class whose vtable is at 0x16c0b40
 * (config/vtables.derived.base.txt, stored by FUN_01005ce0 FUN_01006120),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_01006120 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the three references the object at +0x220 leads to are emptied and the object at +0x290 released while the int at +0x20c is set; the part at +0x308, the block at +0x278 and the array at +0x250 go first of the members, the block at +0x1c0 after the Name. */
class Object016c0b40 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c0b40();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    OwnedBlock05943280 block1c0;           /* +0x1c0: a block released by the destructor */
    u8 unknown1c8[0x34];
    Name name1fc; /* +0x1fc: released by the destructor */
    u8 unknown200[0xc];
    int active20c; /* +0x20c: cleared by the destructor where it is set */
    u8 unknown210[0x8];
    Registry00f516f0 *registry; /* +0x218: the array this object is entered in, or null */
    Owner01006120
        *owner220; /* +0x220: the object whose references are emptied while this one is active */
    AtomicRef0045c470<Node00503fb0> held; /* +0x228: a counted reference */
    u8 unknown230[0x20];
    Array05943280<Element0101ece0> array250; /* +0x250: an array of named elements */
    u8 unknown268[0x10];
    OwnedBlock05943280 block278; /* +0x278: a block released by the destructor */
    u8 unknown280[0x10];
    Released0101ece0
        *object290; /* +0x290: released through its slot 3 while the object is active */
    u8 unknown298[0x70];
    Object013ef2e0 part308; /* +0x308: a member whose destructor is inlined (FUN_013ef2e0) */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x20c and empties the reference at +0x228;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_01006760, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c0b40::~Object016c0b40()
{
    if (registry)
        registry->remove(this);
    if (active20c != 0) {
        if (Refs01006120 *refs = owner220->refs28) {
            refs->ref28.clear();
            refs->ref30.clear();
            refs->ref38.clear();
        }
        if (object290)
            object290->release();
        object290 = 0;
        active20c = 0;
    }
    held.clear();
}
