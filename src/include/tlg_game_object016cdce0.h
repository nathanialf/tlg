/* src/include/tlg_game_object016cdce0.h: the class whose vtable is at 0x16cdce0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDCE0_H
#define TLG_GAME_OBJECT016CDCE0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdce0
 * (config/vtables.derived.base.txt, stored by FUN_009b6090 FUN_01385650), 0x150 bytes
 * (`mov edi, 0x150` before operator new in its creator FUN_009b5f30),
 * derived from Object016b9108 (its constructor 0x9b6090 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016cdce0 : public Object016b9108 /* derived name */
{
  public:
    Object016cdce0(const Name &name); /* 0x9b6090, its row named after it (D15) */
    virtual ~Object016cdce0();

  private:
    u8 unknown24[0x12c];
};

#endif
