/* src/include/tlg_game_object016a8618.h: the class whose vtable is at 0x16a8618
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8618_H
#define TLG_GAME_OBJECT016A8618_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8618
 * (config/vtables.derived.base.txt, stored by FUN_00325a50 FUN_00325ed0), 0x100 bytes
 * (`mov edi, 0x100` before operator new in its creator FUN_003258f0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00325a50 is not written, and its fields are not traced. */
class Object016a8618 : public Object016b9108 /* derived name */
{
  public:
    Object016a8618(const Name &name); /* FUN_00325a50 */
    virtual ~Object016a8618();

  private:
    u8 unknown24[0xdc];
};

#endif
