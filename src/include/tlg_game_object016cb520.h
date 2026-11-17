/* src/include/tlg_game_object016cb520.h: the class whose vtable is at 0x16cb520
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB520_H
#define TLG_GAME_OBJECT016CB520_H

#include "tlg_game_name.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16cb520
 * (config/vtables.derived.base.txt, stored by FUN_006743e0), 0x300 bytes
 * (`mov edi, 0x300` before operator new in its creator FUN_006706e0),
 * derived from Object016b85e0 (its constructor 0x6743e0 first calls 0xc55320, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016cb520 : public Object016b85e0 /* derived name */
{
  public:
    Object016cb520(const Name &name); /* 0x6743e0, its row named after it (D15) */
    virtual ~Object016cb520();

  private:
    u8 unknown8[0x2f8];
};

#endif
