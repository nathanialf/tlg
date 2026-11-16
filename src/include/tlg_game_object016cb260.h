/* src/include/tlg_game_object016cb260.h: the class whose vtable is at 0x16cb260
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB260_H
#define TLG_GAME_OBJECT016CB260_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb260
 * (config/vtables.derived.base.txt, stored by FUN_005c6060 FUN_005c6620), 0x1910 bytes
 * (`mov edi, 0x1910` before operator new in its creator FUN_005c1730),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_005c6060 is not written, and its fields are not traced. */
class Object016cb260 : public Object016b9108 /* derived name */
{
  public:
    Object016cb260(const Name &name); /* FUN_005c6060 */
    virtual ~Object016cb260();

  private:
    u8 unknown24[0x18ec];
};

#endif
