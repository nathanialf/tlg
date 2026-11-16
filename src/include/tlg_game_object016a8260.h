/* src/include/tlg_game_object016a8260.h: the class whose vtable is at 0x16a8260
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8260_H
#define TLG_GAME_OBJECT016A8260_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8260
 * (config/vtables.derived.base.txt, stored by FUN_002eec50), 0x5a0 bytes
 * (`mov edi, 0x5a0` before operator new in its creator FUN_002eeaf0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002eec50 is not written, and its fields are not traced. */
class Object016a8260 : public Object016b9108 /* derived name */
{
  public:
    Object016a8260(const Name &name); /* FUN_002eec50 */
    virtual ~Object016a8260();

  private:
    u8 unknown24[0x57c];
};

#endif
