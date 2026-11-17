/* src/include/tlg_game_object016b02e0.h: the class whose vtable is at 0x16b02e0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B02E0_H
#define TLG_GAME_OBJECT016B02E0_H

#include "tlg_game_name.h"
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16b02e0
 * (config/vtables.derived.base.txt, stored by FUN_008d19c0 FUN_008d2560), 0x268 bytes
 * (`mov edi, 0x268` before operator new in its creator FUN_008c2460),
 * derived from Object016c81c0 (its constructor 0x8d19c0 first calls 0xd68470, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016b02e0 : public Object016c81c0 /* derived name */
{
  public:
    Object016b02e0(const Name &name); /* 0x8d19c0, its row named after it (D15) */
    virtual ~Object016b02e0();

  private:
    u8 unknown98[0x1d0];
};

#endif
