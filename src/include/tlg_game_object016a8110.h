/* src/include/tlg_game_object016a8110.h: the class whose vtable is at 0x16a8110
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8110_H
#define TLG_GAME_OBJECT016A8110_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8110
 * (config/vtables.derived.base.txt, stored by FUN_002c0ad0 FUN_002c1720), 0x3d0 bytes
 * (`mov edi, 0x3d0` before operator new in its creator FUN_002c0970),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002c0ad0 is not written, and its fields are not traced. */
class Object016a8110 : public Object016b9108 /* derived name */
{
  public:
    Object016a8110(const Name &name); /* FUN_002c0ad0 */
    virtual ~Object016a8110();

  private:
    u8 unknown24[0x3ac];
};

#endif
