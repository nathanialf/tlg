/* src/include/tlg_game_object016aeed0.h: the class whose vtable is at 0x16aeed0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEED0_H
#define TLG_GAME_OBJECT016AEED0_H

#include "tlg_game_name.h"
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16aeed0
 * (config/vtables.derived.base.txt, stored by FUN_00844410 FUN_00844590), 0x120 bytes
 * (`mov edi, 0x120` before operator new in its creator FUN_00840e30),
 * derived from Object016c81c0 (its constructor 0x844410 first calls 0xd68470, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016aeed0 : public Object016c81c0 /* derived name */
{
  public:
    Object016aeed0(const Name &name); /* 0x844410, its row named after it (D15) */
    virtual ~Object016aeed0();

  private:
    u8 unknown98[0x88];
};

#endif
