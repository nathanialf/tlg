/* src/include/tlg_game_object016b0408.h: the class whose vtable is at 0x16b0408
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0408_H
#define TLG_GAME_OBJECT016B0408_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0408
 * (config/vtables.derived.base.txt, stored by FUN_008e3e00 FUN_008e4270), 0xb0 bytes
 * (`mov edi, 0xb0` before operator new in its creator FUN_008e3ca0),
 * derived from Object016b9108 (its constructor 0x8e3e00 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016b0408 : public Object016b9108 /* derived name */
{
  public:
    Object016b0408(const Name &name); /* 0x8e3e00, its row named after it (D15) */
    virtual ~Object016b0408();

  private:
    u8 unknown24[0x8c];
};

#endif
