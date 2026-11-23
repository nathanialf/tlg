/* src/include/tlg_game_object016b8d40.h: the class whose vtable is at
 * 0x16b8d40 (config/vtables.derived.base.txt: stored by its constructor
 * 0xca34c0 and its destructors 0xca38f0 and 0xca39b0), a base of other game
 * classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8D40_H
#define TLG_GAME_OBJECT016B8D40_H

#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16b8d40, whose complete
 * destructor is 0xca38f0 (its row named for it, D15). The classes derived from it tail-call that destructor
 * from their own (the files that include this header). The destructor is
 * not written, so nothing here emits the vtable; the class's other slots
 * and its fields are not traced. */
class Object016b8d40 /* derived name */
{
  public:
    Object016b8d40(
        const Name &
            name); /* 0xca34c0, its row named after it (D15): the derived classes' creators call it (FUN_00b1f270) */
    virtual ~Object016b8d40();
};

#endif
