/* src/include/tlg_game_object016b85e0.h: the class whose vtable is at
 * 0x16b85e0, a base of many game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B85E0_H
#define TLG_GAME_OBJECT016B85E0_H

#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16b85e0
 * (config/vtables.derived.base.txt, stored by its constructor 0xc55320 and
 * its complete destructor 0xc55550; both rows named for it, D15). The classes derived from it tail-call that destructor
 * from their own (leaf_0080b1e0.cpp and the files that include this header).
 * The destructor is not written, so nothing here emits the vtable; the
 * class's other slots and its fields are not traced. */
class Object016b85e0 /* derived name */
{
  public:
    Object016b85e0(
        const Name
            &name); /* 0xc55320, its row named after it (D15): it passes the name to FUN_00cb6310 */
    virtual ~Object016b85e0();
};

#endif
