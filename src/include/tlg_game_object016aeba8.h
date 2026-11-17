/* src/include/tlg_game_object016aeba8.h: the class whose vtable is at 0x16aeba8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEBA8_H
#define TLG_GAME_OBJECT016AEBA8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aeba8
 * (config/vtables.derived.base.txt, stored by FUN_0082d3d0 FUN_0082d620), 0x148 bytes
 * (`mov edi, 0x148` before operator new in its creator FUN_0082aa80),
 * derived from Object016b9108 (its constructor 0x82d3d0 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016aeba8 : public Object016b9108 /* derived name */
{
  public:
    Object016aeba8(const Name &name); /* 0x82d3d0, its row named after it (D15) */
    virtual ~Object016aeba8();

  private:
    u8 unknown24[0x124];
};

#endif
