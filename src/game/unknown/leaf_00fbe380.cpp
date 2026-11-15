/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c0180
 * (config/vtables.derived.base.txt, stored by FUN_00fbde90 FUN_00fbe380),
 * derived from Object00c1b7f0. Its fields are traced only where its
 * destructor FUN_00fbe380 uses them: the shape of FUN_00f1a950
 * (leaf_00f1a950.cpp) with the members at this class's offsets;
 * the ten arrays from +0x210 are emptied and their blocks let go while the int at +0x1d0 is set (+0x210, +0x240, +0x270, then +0x228, +0x258, +0x288, then the last four). */
class Object016c0180 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016c0180();

  private:
    Object013cd320 part40;                 /* +0x40 */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    Name name1c0;                          /* +0x1c0: released by the destructor */
    u8 unknown1c4[0xc];
    int active1d0; /* +0x1d0: cleared by the destructor where it is set */
    u8 unknown1d4[0x4];
    Registry00f516f0 *registry;           /* +0x1d8: the array this object is entered in, or null */
    void *unknown1e0;                     /* +0x1e0: not traced */
    AtomicRef0045c470<Node00503fb0> held; /* +0x1e8: a counted reference */
    u8 unknown1f0[0x20];
    Array05943280<int>
        array210; /* +0x210: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array228; /* +0x228: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array240; /* +0x240: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array258; /* +0x258: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array270; /* +0x270: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array288; /* +0x288: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array2a0; /* +0x2a0: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array2b8; /* +0x2b8: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array2d0; /* +0x2d0: an array emptied and its block let go while the object is active; the element is not traced */
    Array05943280<int>
        array2e8; /* +0x2e8: an array emptied and its block let go while the object is active; the element is not traced */
};

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x1d0 and empties the reference at +0x1e8;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00fbec90, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c0180::~Object016c0180()
{
    if (registry)
        registry->remove(this);
    if (active1d0 != 0) {
        array210.freeBlock();
        array240.freeBlock();
        array270.freeBlock();
        array228.freeBlock();
        array258.freeBlock();
        array288.freeBlock();
        array2a0.freeBlock();
        array2b8.freeBlock();
        array2d0.freeBlock();
        array2e8.freeBlock();
        active1d0 = 0;
    }
    held.clear();
}
