/* src/include/tlg_game_object016cb8f8.h: the class whose vtable is at 0x16cb8f8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB8F8_H
#define TLG_GAME_OBJECT016CB8F8_H

#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16cb8f8
 * (config/vtables.derived.base.txt, stored by FUN_00783b40 FUN_00f871d0 FUN_0136b9f0), 0x780 bytes
 * (`mov edi, 0x780` before operator new in its creator FUN_0077c690),
 * derived from Object00774560 (its constructor 0x783b40 first calls 0x774370, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016cb8f8 : public Object00774560 /* derived name */
{
  public:
    Object016cb8f8(const Name &name); /* 0x783b40, its row named after it (D15) */
    virtual ~Object016cb8f8();

  private:
    u8 unknownfc[0x684];
};

#endif
