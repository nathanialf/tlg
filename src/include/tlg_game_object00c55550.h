/* src/include/tlg_game_object00c55550.h: the class whose destructor is
 * 0xc55550, a base of many game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT00C55550_H
#define TLG_GAME_OBJECT00C55550_H

#include "tlg_game_name.h"

/* derived names: the class whose complete destructor is 0xc55550 (its row
 * named for it, D15; its vtable is at 0x16b85e0, stored by FUN_00c55320 and
 * that destructor). The classes derived from it tail-call that destructor
 * from their own (leaf_0080b1e0.cpp and the files that include this header).
 * The destructor is not written, so nothing here emits the vtable; the
 * class's other slots and its fields are not traced. */
class Object00c55550 /* derived name */
{
  public:
    Object00c55550(
        const Name
            &name); /* 0xc55320, its row named after it (D15): it passes the name to FUN_00cb6310 */
    virtual ~Object00c55550();
};

#endif
