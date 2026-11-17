/* src/include/tlg_game_object016addb8.h: the class whose vtable is at 0x16addb8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADDB8_H
#define TLG_GAME_OBJECT016ADDB8_H

#include "tlg_game_name.h"
#include "tlg_game_object016c7880.h"

/* derived names: the class whose vtable is at 0x16addb8
 * (config/vtables.derived.base.txt, stored by FUN_007aa1d0 FUN_007aa640), 0x3d0 bytes
 * (`mov edi, 0x3d0` before operator new in its creator FUN_007a6be0),
 * derived from Object016c7880 (its constructor 0x7aa1d0 first calls 0x7a7110, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016addb8 : public Object016c7880 /* derived name */
{
  public:
    Object016addb8(const Name &name); /* 0x7aa1d0, its row named after it (D15) */
    virtual ~Object016addb8();

  private:
    u8 unknownb8[0x318];
};

#endif
