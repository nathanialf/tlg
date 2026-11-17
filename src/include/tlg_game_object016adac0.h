/* src/include/tlg_game_object016adac0.h: the class whose vtable is at 0x16adac0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADAC0_H
#define TLG_GAME_OBJECT016ADAC0_H

#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16adac0
 * (config/vtables.derived.base.txt, stored by FUN_0079dac0 FUN_0079dbc0), 0x420 bytes
 * (`mov edi, 0x420` before operator new in its creator FUN_0079d960),
 * derived from Object00774560 (its constructor 0x79dac0 first calls 0x774370, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016adac0 : public Object00774560 /* derived name */
{
  public:
    Object016adac0(const Name &name); /* 0x79dac0, its row named after it (D15) */
    virtual ~Object016adac0();

  private:
    u8 unknownfc[0x324];
};

#endif
