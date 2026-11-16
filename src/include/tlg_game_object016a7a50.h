/* src/include/tlg_game_object016a7a50.h: the class whose vtable is at 0x16a7a50
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7A50_H
#define TLG_GAME_OBJECT016A7A50_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7a50
 * (config/vtables.derived.base.txt, stored by FUN_00297190 FUN_00297320), 0x5e0 bytes
 * (`mov edi, 0x5e0` before operator new in its creator FUN_00297030),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00297190 is not written, and its fields are not traced. */
class Object016a7a50 : public Object016b9108 /* derived name */
{
  public:
    Object016a7a50(const Name &name); /* FUN_00297190 */
    virtual ~Object016a7a50();

  private:
    u8 unknown24[0x5bc];
};

#endif
