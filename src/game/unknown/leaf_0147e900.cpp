/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object016ca768.h"
#include "tlg_game_object016d6b08.h"
#include "tlg_math.h"

/* derived name: the complete destructor (slot 0 of 0x16d6b08): the body is
 * empty; the Name at +0x30 is released, then the block at +0x18.
 * FUN_0147e9a0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016d6b08::~Object016d6b08() {}

/* derived names: the class whose vtable is at 0x16d6b50
 * (config/vtables.derived.base.txt, stored by FUN_00122be10 and its two
 * destructors), derived from Object016d6b08: slot 2 is its own
 * (FUN_0147d3c0), slot 3 the base's. Its own fields from +0x34 are traced
 * only where slot 2 and the destructor use them (the array at +0x70). The
 * destructor is the implicit one (inline): slot 2 is the key function, so
 * this file emits the vtable and with it the two destructors, the
 * deleting one inlining the complete one (0x147ea40 and 0x147eb20 hold the
 * same body). The executable folds this destructor pair with those of four
 * more classes of the same shape (slots 0 and 1 of five vtables hold
 * 0x147ea40 and 0x147eb20): it is claimed from this class, the one with a
 * vtable row. */
class Object016d6b50 : public Object016d6b08 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */

  private:
    u8 unknown34[0x3c];
    /* +0x70: an array emptied by slot 2 and released by the destructor;
     * its elements are not traced: 16-byte aligned (the reallocation's
     * alignment 0x10), nothing to destroy */
    Array05943280<Float4A> array70;
};

/* derived name: the base's slot 2, then the array emptied and its block given
 * back (`mov dword [rbx+0x78], 0; cmp dword [rbx+0x7c], 0; je`, the
 * reallocation to no bytes) */
void Object016d6b50::slot2()
{
    Object016d6b08::slot2();
    array70.clear();
}

/* the destructor of Object016cab48 (tlg_game_object016ca768.h), its key function: in
 * the unit of its base's, which it inlines as the base's other derived
 * classes do */
Object016cab48::~Object016cab48()
{
    pool.shutdown();
}

/* the destructors of Object016ca8b0 and Object016caa48
 * (tlg_game_object016ca768.h), their key functions: in the unit of their
 * base's, which they inline */
Object016ca8b0::~Object016ca8b0()
{
    pool.shutdown();
}

Object016caa48::~Object016caa48()
{
    pool.shutdown();
}
