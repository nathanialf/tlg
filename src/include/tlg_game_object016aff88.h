/* src/include/tlg_game_object016aff88.h: the class whose vtable is at 0x16aff88
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AFF88_H
#define TLG_GAME_OBJECT016AFF88_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aff88
 * (config/vtables.derived.base.txt, stored by FUN_008b5220 FUN_008b54e0), 0x1a0 bytes
 * (`mov edi, 0x1a0` before operator new in its creator FUN_008b2700),
 * derived from Object016b9108 (its constructor 0x8b5220 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016aff88 : public Object016b9108 /* derived name */
{
  public:
    Object016aff88(const Name &name); /* 0x8b5220, its row named after it (D15) */
    virtual ~Object016aff88();

  private:
    u8 unknown24[0x17c];
};

#endif
