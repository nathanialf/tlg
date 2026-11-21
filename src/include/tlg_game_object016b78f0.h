/* src/include/tlg_game_object016b78f0.h: the class whose vtable is at
 * 0x16b78f0, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B78F0_H
#define TLG_GAME_OBJECT016B78F0_H

#include "tlg_game_array.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the elements of two of its arrays, four bytes with nothing
 * to release (`mov ecx, 4` to the block's reallocation); not traced */
struct Element016b78f0 {
    u32 unknown0;
};

/* derived names: the class whose vtable is at 0x16b78f0
 * (config/vtables.derived.base.txt, stored by its constructors FUN_00ae8350
 * and FUN_00bdd0d0 and its destructor FUN_00bde1c0, whose row is named for
 * it, D15), derived from Object016b9108: its slots 2 to 4 are the base's,
 * slot 5 FUN_00c1b340 and slot 6 FUN_00c1b350. Its destructor is its key
 * function (leaf_00bde1c0.cpp): the deleting one FUN_00bde4e0 calls it; the
 * class at 0x16b3e30 (leaf_00ae8570.cpp) derives from it. Its fields are
 * traced where the destructor tears them down: an array of counted
 * references at +0x28 and two of four-byte elements at +0x48 and +0x60,
 * each emptied to no capacity first. */
class Object016b78f0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b78f0();
    virtual void slot5(); /* derived name; FUN_00c1b340, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0x4];
    Object0134f620 array28; /* +0x28 */
    u8 unknown40[0x8];
    Array05943280<Element016b78f0> array48; /* +0x48 */
    Array05943280<Element016b78f0> array60; /* +0x60 */
};

#endif
