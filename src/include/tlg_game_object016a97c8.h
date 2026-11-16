/* src/include/tlg_game_object016a97c8.h: the class whose vtable is at 0x16a97c8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A97C8_H
#define TLG_GAME_OBJECT016A97C8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a97c8
 * (config/vtables.derived.base.txt, stored by FUN_00405170 FUN_004066c0), 0x220 bytes
 * (`mov edi, 0x220` before operator new in its creator FUN_00405010),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00405170 is not written, and its fields are not traced. */
class Object016a97c8 : public Object016b9108 /* derived name */
{
  public:
    Object016a97c8(const Name &name); /* FUN_00405170 */
    virtual ~Object016a97c8();

  private:
    u8 unknown24[0x1fc];
};

#endif
