/* src/include/tlg_game_object016aec68.h: the class whose vtable is at 0x16aec68
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEC68_H
#define TLG_GAME_OBJECT016AEC68_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aec68
 * (config/vtables.derived.base.txt, stored by FUN_008373c0 FUN_00837640), 0x280 bytes
 * (`mov edi, 0x280` before operator new in its creator FUN_00830e50),
 * derived from Object016b9108 (its constructor 0x8373c0 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016aec68 : public Object016b9108 /* derived name */
{
  public:
    Object016aec68(const Name &name); /* 0x8373c0, its row named after it (D15) */
    virtual ~Object016aec68();

  private:
    u8 unknown24[0x25c];
};

#endif
