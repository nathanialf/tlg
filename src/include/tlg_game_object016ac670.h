/* src/include/tlg_game_object016ac670.h: the class whose vtable is at 0x16ac670
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AC670_H
#define TLG_GAME_OBJECT016AC670_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ac670
 * (config/vtables.derived.base.txt, stored by FUN_006d2bf0 FUN_006d5ba0), 0x5500 bytes
 * (`mov edi, 0x5500` before operator new in its creator FUN_0069d530),
 * derived from Object016b9108 (its constructor 0x6d2bf0 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016ac670 : public Object016b9108 /* derived name */
{
  public:
    Object016ac670(const Name &name); /* 0x6d2bf0, its row named after it (D15) */
    virtual ~Object016ac670();

  private:
    u8 unknown24[0x54dc];
};

#endif
