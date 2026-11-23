/* src/include/tlg_game_object016cb610.h: the class whose vtable is at
 * 0x16cb610 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB610_H
#define TLG_GAME_OBJECT016CB610_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb610
 * (config/vtables.derived.base.txt, stored by its creator FUN_0069b300,
 * leaf_0069b300.cpp, and its destructor FUN_01360490), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x60 bytes: an empty Name at +0x24, 8 bytes of zero at +0x28 and
 * two locked arrays of Names at +0x30 and +0x48, empty, all from the
 * constructor. The destructor is implicit: the complete one,
 * FUN_01360460, is a jump to the base-object one, FUN_01360490 (the
 * arrays of Names last to first, their elements released, then the Name,
 * then the root's destructor in line), and the deleting one,
 * FUN_01360470, calls it: its cost is over the inline limit of 325 (the
 * inline hint). The class has no key function, so the creator's unit
 * emits the vtable with them. */
class Object016cb610 : public Object016b9108 /* derived name */
{
  public:
    Object016cb610(const Name &name) : Object016b9108(name), unknown28(0) {}

  private:
    Name name24;                 /* +0x24 */
    void *unknown28;             /* +0x28: null from the constructor */
    Array01343a80<Name> names30; /* +0x30 */
    Array01343a80<Name> names48; /* +0x48 */
};

#endif
