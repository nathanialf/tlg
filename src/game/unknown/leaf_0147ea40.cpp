/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d6b08.h"

/* derived names: the class whose vtable is at 0x16d6b50
 * (config/vtables.derived.base.txt, stored by FUN_0122be10 and its two
 * destructors), derived from Object016d6b08: slot 2 is its own
 * (FUN_0147d3c0), slot 3 the base's. Its own fields from +0x34 are traced
 * only where its destructor tears them down (the block at +0x70). The
 * executable folds this destructor pair with those of four more classes of
 * the same shape (slots 0 and 1 of five vtables hold 0x147ea40 and
 * 0x147eb20): it is claimed from this class, the one with a vtable row. */
class Object016d6b50 : public Object016d6b08 /* derived name */
{
  public:
    virtual ~Object016d6b50();
    virtual void slot2(); /* derived name; FUN_0147d3c0, not traced */

  private:
    u8 unknown34[0x3c];
    /* +0x70: an owned block, released by the destructor (`mov rax, [rbx+0x70]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block70;
};

/* derived name: the complete destructor: the body is empty; the block at
 * +0x70 is released, then the base's destructor is inlined (its vptr store,
 * the Name at +0x30, the block at +0x18). FUN_0147eb20, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016d6b50::~Object016d6b50() {}
