/* src/include/tlg_game_object016cb428.h: the class whose vtable is at 0x16cb428
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB428_H
#define TLG_GAME_OBJECT016CB428_H

#include "tlg_game_name.h"
#include "tlg_game_object016c7d08.h"

/* derived names: the class whose vtable is at 0x16cb428
 * (config/vtables.derived.base.txt, stored by FUN_006339a0), 0x5040 bytes
 * (`mov edi, 0x5040` before operator new in its creator FUN_00628560),
 * derived from Object016c7d08 (its constructor 0x6339a0 first calls 0xafd2e0, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016cb428 : public Object016c7d08 /* derived name */
{
  public:
    Object016cb428(const Name &name); /* 0x6339a0, its row named after it (D15) */
    virtual ~Object016cb428();

  private:
    u8 unknown60[0x4fe0];
};

#endif
