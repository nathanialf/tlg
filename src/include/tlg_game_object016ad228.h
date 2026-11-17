/* src/include/tlg_game_object016ad228.h: the class whose vtable is at 0x16ad228
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD228_H
#define TLG_GAME_OBJECT016AD228_H

#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad228
 * (config/vtables.derived.base.txt, stored by FUN_007795c0 FUN_007796c0), 0x3f0 bytes
 * (`mov edi, 0x3f0` before operator new in its creator FUN_00779460),
 * derived from Object00774560 (its constructor 0x7795c0 first calls 0x774370, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016ad228 : public Object00774560 /* derived name */
{
  public:
    Object016ad228(const Name &name); /* 0x7795c0, its row named after it (D15) */
    virtual ~Object016ad228();

  private:
    u8 unknownfc[0x2f4];
};

#endif
