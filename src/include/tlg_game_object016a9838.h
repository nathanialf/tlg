/* src/include/tlg_game_object016a9838.h: the class whose vtable is at 0x16a9838
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9838_H
#define TLG_GAME_OBJECT016A9838_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9838
 * (config/vtables.derived.base.txt, stored by FUN_00412a80 FUN_004143d0), 0x800 bytes
 * (`mov edi, 0x800` before operator new in its creator FUN_00407f70),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00412a80 is not written, and its fields are not traced. */
class Object016a9838 : public Object016b9108 /* derived name */
{
  public:
    Object016a9838(const Name &name); /* FUN_00412a80 */
    virtual ~Object016a9838();

  private:
    u8 unknown24[0x7dc];
};

#endif
