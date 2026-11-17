/* src/include/tlg_game_object016af2d8.h: the class whose vtable is at 0x16af2d8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AF2D8_H
#define TLG_GAME_OBJECT016AF2D8_H

#include "tlg_game_name.h"
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16af2d8
 * (config/vtables.derived.base.txt, stored by FUN_0087fe50 FUN_00880310), 0x250 bytes
 * (`mov edi, 0x250` before operator new in its creator FUN_00879880),
 * derived from Object016c81c0 (its constructor 0x87fe50 first calls 0xd68470, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016af2d8 : public Object016c81c0 /* derived name */
{
  public:
    Object016af2d8(const Name &name); /* 0x87fe50, its row named after it (D15) */
    virtual ~Object016af2d8();

  private:
    u8 unknown98[0x1b8];
};

#endif
