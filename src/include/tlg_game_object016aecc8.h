/* src/include/tlg_game_object016aecc8.h: the class whose vtable is at 0x16aecc8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AECC8_H
#define TLG_GAME_OBJECT016AECC8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aecc8
 * (config/vtables.derived.base.txt, stored by FUN_0083cf60 FUN_01370850), 0xa0 bytes
 * (`mov edi, 0xa0` before operator new in its creator FUN_0083ce00),
 * derived from Object016b9108 (its constructor 0x83cf60 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016aecc8 : public Object016b9108 /* derived name */
{
  public:
    Object016aecc8(const Name &name); /* 0x83cf60, its row named after it (D15) */
    virtual ~Object016aecc8();

  private:
    u8 unknown24[0x7c];
};

#endif
