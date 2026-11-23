/* src/include/tlg_game_object016ce1d0.h: the class whose vtable is at
 * 0x16ce1d0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE1D0_H
#define TLG_GAME_OBJECT016CE1D0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ce1d0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00a17070,
 * leaf_00a17070.cpp, and its destructor FUN_0138af70), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x58 bytes: an empty Name at +0x24 and two locked arrays of
 * Names at +0x28 and +0x40, empty from the constructor. The destructor is
 * implicit: the complete one, FUN_0138af40, is a jump to the base-object
 * one, FUN_0138af70 (the arrays of Names last to first, their elements
 * released, then the Name, then the root's destructor in line), and the
 * deleting one, FUN_0138af50, calls it: its cost is over the inline limit
 * of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016ce1d0 : public Object016b9108 /* derived name */
{
  public:
    Object016ce1d0(const Name &name) : Object016b9108(name) {}

  private:
    Name name24;                 /* +0x24 */
    Array01343a80<Name> names28; /* +0x28 */
    Array01343a80<Name> names40; /* +0x40 */
};

#endif
