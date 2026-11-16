/* src/include/tlg_game_object016a8650.h: the class whose vtable is at 0x16a8650
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8650_H
#define TLG_GAME_OBJECT016A8650_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8650
 * (config/vtables.derived.base.txt, stored by FUN_0032e7e0 FUN_0032ed50), 0x27b0 bytes
 * (`mov edi, 0x27b0` before operator new in its creator FUN_00326ab0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0032e7e0 is not written, and its fields are not traced. */
class Object016a8650 : public Object016b9108 /* derived name */
{
  public:
    Object016a8650(const Name &name); /* FUN_0032e7e0 */
    virtual ~Object016a8650();

  private:
    u8 unknown24[0x278c];
};

#endif
