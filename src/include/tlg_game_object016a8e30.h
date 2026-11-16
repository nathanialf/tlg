/* src/include/tlg_game_object016a8e30.h: the class whose vtable is at 0x16a8e30
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8E30_H
#define TLG_GAME_OBJECT016A8E30_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8e30
 * (config/vtables.derived.base.txt, stored by FUN_00396440 FUN_00398d90), 0x3c50 bytes
 * (`mov edi, 0x3c50` before operator new in its creator FUN_00387450),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00396440 is not written, and its fields are not traced. */
class Object016a8e30 : public Object016b9108 /* derived name */
{
  public:
    Object016a8e30(const Name &name); /* FUN_00396440 */
    virtual ~Object016a8e30();

  private:
    u8 unknown24[0x3c2c];
};

#endif
