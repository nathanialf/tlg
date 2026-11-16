/* src/include/tlg_game_object016c7948.h: the class whose vtable is at 0x16c7948
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7948_H
#define TLG_GAME_OBJECT016C7948_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7948
 * (config/vtables.derived.base.txt, stored by FUN_00344a60 FUN_0035b770 FUN_00510130 and 3 more), 0x2f0 bytes
 * (`mov edi, 0x2f0` before operator new in its creator FUN_00344900),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00344a60 is not written, and its fields are not traced. */
class Object016c7948 : public Object016b9108 /* derived name */
{
  public:
    Object016c7948(const Name &name); /* FUN_00344a60 */
    virtual ~Object016c7948();

  private:
    u8 unknown24[0x2cc];
};

#endif
