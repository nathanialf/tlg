/* src/include/tlg_game_object016b16e0.h: the class whose vtable is at 0x16b16e0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B16E0_H
#define TLG_GAME_OBJECT016B16E0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b16e0
 * (config/vtables.derived.base.txt, stored by FUN_00973860 FUN_00977270), 0x9f0 bytes
 * (`mov edi, 0x9f0` before operator new in its creator FUN_0096f0d0),
 * derived from Object016b9108 (its constructor 0x973860 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016b16e0 : public Object016b9108 /* derived name */
{
  public:
    Object016b16e0(const Name &name); /* 0x973860, its row named after it (D15) */
    virtual ~Object016b16e0();

  private:
    u8 unknown24[0x9cc];
};

#endif
