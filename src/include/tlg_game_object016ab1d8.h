/* src/include/tlg_game_object016ab1d8.h: the class whose vtable is at 0x16ab1d8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB1D8_H
#define TLG_GAME_OBJECT016AB1D8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab1d8
 * (config/vtables.derived.base.txt, stored by FUN_00515850 FUN_00515fc0), 0x430 bytes
 * (`mov edi, 0x430` before operator new in its creator FUN_00511380),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00515850 is not written, and its fields are not traced. */
class Object016ab1d8 : public Object016b9108 /* derived name */
{
  public:
    Object016ab1d8(const Name &name); /* FUN_00515850 */
    virtual ~Object016ab1d8();

  private:
    u8 unknown24[0x40c];
};

#endif
