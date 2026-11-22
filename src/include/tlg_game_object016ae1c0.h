/* src/include/tlg_game_object016ae1c0.h: the class whose vtable is at 0x16ae1c0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE1C0_H
#define TLG_GAME_OBJECT016AE1C0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16ae1c0
 * (config/vtables.derived.base.txt, stored by FUN_007f8f10 FUN_007f9370), 0x440 bytes
 * (`mov edi, 0x440` before operator new in its creator FUN_007f4f70),
 * derived from Object016b85e0 (its constructor 0x7f8f10 first calls 0xc55320, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016ae1c0 : public Object016b85e0 /* derived name */
{
  public:
    Object016ae1c0(const Name &name); /* 0x7f8f10, its row named after it (D15) */
    virtual ~Object016ae1c0();

  private:
    u8 unknown238[0x208];
};

#endif
