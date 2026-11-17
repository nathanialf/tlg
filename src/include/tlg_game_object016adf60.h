/* src/include/tlg_game_object016adf60.h: the class whose vtable is at 0x16adf60
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADF60_H
#define TLG_GAME_OBJECT016ADF60_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16adf60
 * (config/vtables.derived.base.txt, stored by FUN_007b2850 FUN_007b2a80 FUN_007b2b40), 0x130 bytes
 * (`mov edi, 0x130` before operator new in its creator FUN_007b26f0),
 * derived from Object016b9108 (its constructor 0x7b2850 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016adf60 : public Object016b9108 /* derived name */
{
  public:
    Object016adf60(const Name &name); /* 0x7b2850, its row named after it (D15) */
    virtual ~Object016adf60();

  private:
    u8 unknown24[0x10c];
};

#endif
