/* src/include/tlg_game_object016ae2c8.h: the class whose vtable is at 0x16ae2c8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE2C8_H
#define TLG_GAME_OBJECT016AE2C8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16ae2c8
 * (config/vtables.derived.base.txt, stored by FUN_0080b010), 0x240 bytes
 * (`mov edi, 0x240` before operator new in its creator FUN_0080ad50),
 * derived from Object016b85e0 (its constructor 0x80b010 first calls 0xc55320, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016ae2c8 : public Object016b85e0 /* derived name */
{
  public:
    Object016ae2c8(const Name &name); /* 0x80b010, its row named after it (D15) */
    virtual ~Object016ae2c8();

  private:
    u8 unknown238[0x8];
};

#endif
