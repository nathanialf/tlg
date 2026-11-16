/* src/include/tlg_game_object016c71d0.h: the class whose vtable is at 0x16c71d0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C71D0_H
#define TLG_GAME_OBJECT016C71D0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c71d0
 * (config/vtables.derived.base.txt, stored by FUN_0021c020 FUN_01346cc0), 0x280 bytes
 * (`mov edi, 0x280` before operator new in its creator FUN_00218b90),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0021c020 is not written, and its fields are not traced. */
class Object016c71d0 : public Object016b9108 /* derived name */
{
  public:
    Object016c71d0(const Name &name); /* FUN_0021c020 */
    virtual ~Object016c71d0();

  private:
    u8 unknown24[0x25c];
};

#endif
