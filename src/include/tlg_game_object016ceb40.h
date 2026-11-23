/* src/include/tlg_game_object016ceb40.h: the class whose vtable is at
 * 0x16ceb40 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CEB40_H
#define TLG_GAME_OBJECT016CEB40_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ceb40
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b005b0,
 * leaf_00b005b0.cpp, and its destructor FUN_0138f5f0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x58 bytes: an empty Name at +0x24, then two locked arrays from
 * the constructor, at +0x28 (its elements have no destructor; not traced)
 * and at +0x40 (Names). The destructor is implicit: the complete one,
 * FUN_0138f5c0, is a jump to the base-object one, FUN_0138f5f0 (the array
 * of Names, its elements released, then the other array's block and the
 * Name, then the root's destructor in line), and the deleting one,
 * FUN_0138f5d0, calls it: its cost is over the inline limit of 325 (the
 * inline hint). The class has no key function, so the creator's unit
 * emits the vtable with them. */
class Object016ceb40 : public Object016b9108 /* derived name */
{
  public:
    Object016ceb40(const Name &name) : Object016b9108(name) {}

  private:
    Name name24;                  /* +0x24 */
    Array01343a80<int> unknown28; /* +0x28: the element not traced */
    Array01343a80<Name> names40;  /* +0x40 */
};

#endif
