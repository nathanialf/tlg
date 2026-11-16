/* src/include/tlg_game_object016c7560.h: the class whose vtable is at 0x16c7560
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7560_H
#define TLG_GAME_OBJECT016C7560_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7560
 * (config/vtables.derived.base.txt, stored by FUN_0033e000 FUN_0134cb30), 0x1e0 bytes
 * (`mov edi, 0x1e0` before operator new in its creator FUN_0033dea0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0033e000 is not written, and its fields are not traced. */
class Object016c7560 : public Object016b9108 /* derived name */
{
  public:
    Object016c7560(const Name &name); /* FUN_0033e000 */
    virtual ~Object016c7560();

  private:
    u8 unknown24[0x1bc];
};

#endif
