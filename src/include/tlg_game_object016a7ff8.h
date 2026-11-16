/* src/include/tlg_game_object016a7ff8.h: the class whose vtable is at 0x16a7ff8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7FF8_H
#define TLG_GAME_OBJECT016A7FF8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7ff8
 * (config/vtables.derived.base.txt, stored by FUN_002bc420 FUN_002bc5b0), 0x90 bytes
 * (`mov edi, 0x90` before operator new in its creator FUN_002bc2c0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002bc420 is not written, and its fields are not traced. */
class Object016a7ff8 : public Object016b9108 /* derived name */
{
  public:
    Object016a7ff8(const Name &name); /* FUN_002bc420 */
    virtual ~Object016a7ff8();

  private:
    u8 unknown24[0x6c];
};

#endif
