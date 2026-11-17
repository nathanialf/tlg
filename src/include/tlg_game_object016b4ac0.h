/* src/include/tlg_game_object016b4ac0.h: the class whose vtable is at 0x16b4ac0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4AC0_H
#define TLG_GAME_OBJECT016B4AC0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b4ac0
 * (config/vtables.derived.base.txt, stored by FUN_00704230), 0xade0 bytes
 * (`mov edi, 0xade0` before operator new in its creator FUN_006e1da0),
 * derived from Object016b9108 (its constructor 0x704230 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016b4ac0 : public Object016b9108 /* derived name */
{
  public:
    Object016b4ac0(const Name &name); /* 0x704230, its row named after it (D15) */
    virtual ~Object016b4ac0();

  private:
    u8 unknown24[0xadbc];
};

#endif
