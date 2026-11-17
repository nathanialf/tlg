/* src/include/tlg_game_object016cb648.h: the class whose vtable is at 0x16cb648
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB648_H
#define TLG_GAME_OBJECT016CB648_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb648
 * (config/vtables.derived.base.txt, stored by FUN_0069bed0 FUN_01360730), 0x148 bytes
 * (`mov edi, 0x148` before operator new in its creator FUN_0069bd70),
 * derived from Object016b9108 (its constructor 0x69bed0 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016cb648 : public Object016b9108 /* derived name */
{
  public:
    Object016cb648(const Name &name); /* 0x69bed0, its row named after it (D15) */
    virtual ~Object016cb648();

  private:
    u8 unknown24[0x124];
};

#endif
