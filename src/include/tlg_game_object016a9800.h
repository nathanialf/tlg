/* src/include/tlg_game_object016a9800.h: the class whose vtable is at 0x16a9800
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9800_H
#define TLG_GAME_OBJECT016A9800_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9800
 * (config/vtables.derived.base.txt, stored by FUN_00407ab0 FUN_00407c50), 0x70 bytes
 * (`mov edi, 0x70` before operator new in its creator FUN_00407950),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00407ab0 is not written, and its fields are not traced. */
class Object016a9800 : public Object016b9108 /* derived name */
{
  public:
    Object016a9800(const Name &name); /* FUN_00407ab0 */
    virtual ~Object016a9800();

  private:
    u8 unknown24[0x4c];
};

#endif
