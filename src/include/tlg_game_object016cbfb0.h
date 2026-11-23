/* src/include/tlg_game_object016cbfb0.h: the class whose vtable is at
 * 0x16cbfb0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBFB0_H
#define TLG_GAME_OBJECT016CBFB0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbfb0
 * (config/vtables.derived.base.txt, stored by its creator FUN_0081ac60,
 * leaf_0081ac60.cpp, and its destructor FUN_0136f890), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0xb8 bytes: six locked arrays from +0x28, empty from the
 * constructor: of counted references (+0x28), of Names (+0x40, +0x58) and
 * three whose elements have no destructor (+0x70, +0x88, +0xa0; not
 * traced). The destructor is implicit: the complete one, FUN_0136f880, is
 * a jump to the base-object one, FUN_0136f890 (the arrays last to first,
 * the Names released, the references' through their destructor
 * FUN_0134f620, then the root's destructor in line), and the deleting
 * one, FUN_0136fb20, calls it: its cost is over the inline limit of 325
 * (the inline hint). The class has no key function, so the creator's unit
 * emits the vtable with them. */
class Object016cbfb0 : public Object016b9108 /* derived name */
{
  public:
    Object016cbfb0(const Name &name) : Object016b9108(name) {}

  private:
    u8 unknown24[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> references28; /* +0x28 */
    Array01343a80<Name> names40;                             /* +0x40 */
    Array01343a80<Name> names58;                             /* +0x58 */
    Array01343a80<int> unknown70;                            /* +0x70: the element not traced */
    Array01343a80<int> unknown88;                            /* +0x88: the element not traced */
    Array01343a80<int> unknowna0;                            /* +0xa0: the element not traced */
};

#endif
