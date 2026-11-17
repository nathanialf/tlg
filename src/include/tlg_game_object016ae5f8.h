/* src/include/tlg_game_object016ae5f8.h: the class whose vtable is at 0x16ae5f8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE5F8_H
#define TLG_GAME_OBJECT016AE5F8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ae5f8
 * (config/vtables.derived.base.txt, stored by FUN_008125d0 FUN_00812ac0), 0x1240 bytes
 * (`mov edi, 0x1240` before operator new in its creator FUN_00812470),
 * derived from Object016b9108 (its constructor 0x8125d0 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016ae5f8 : public Object016b9108 /* derived name */
{
  public:
    Object016ae5f8(const Name &name); /* 0x8125d0, its row named after it (D15) */
    virtual ~Object016ae5f8();

  private:
    u8 unknown24[0x121c];
};

#endif
