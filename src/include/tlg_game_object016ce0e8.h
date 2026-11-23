/* src/include/tlg_game_object016ce0e8.h: the class whose vtable is at
 * 0x16ce0e8 (config/vtables.derived.base.txt, stored by FUN_00a050e0
 * FUN_01388c00); leaf_00a050e0.cpp defines its constructor. Every name here
 * is derived. */
#ifndef TLG_GAME_OBJECT016CE0E8_H
#define TLG_GAME_OBJECT016CE0E8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: derived from the counted base Counted00c14bc0: its three
 * slots are the two destructors and the base's release. 0x28 bytes: three
 * counted references another thread may replace, at +0x10, +0x18 and +0x20,
 * empty from the constructor (one 16-byte store and an 8-byte one), then
 * each set in its body to an object FUN_00a05e80 makes of the kind passed.
 * The destructor is implicit: the complete one, FUN_01388bd0, is a jump to
 * the base-object one, FUN_01388c00 (the references released last to
 * first), and the deleting one, FUN_01388be0, calls it: its cost is over the
 * inline limit of 325 (the inline hint). The class has no key function, so
 * the constructor's unit emits the vtable with them. */
class Object016ce0e8 : public Counted00c14bc0 /* derived name */
{
  public:
    explicit Object016ce0e8(int kind); /* FUN_00a050e0 */

  private:
    AtomicRef0045c470<Object016b9108> unknown10; /* +0x10 */
    AtomicRef0045c470<Object016b9108> unknown18; /* +0x18 */
    AtomicRef0045c470<Object016b9108> unknown20; /* +0x20 */
};

#endif
