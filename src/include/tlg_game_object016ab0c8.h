/* src/include/tlg_game_object016ab0c8.h: the class whose vtable is at 0x16ab0c8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB0C8_H
#define TLG_GAME_OBJECT016AB0C8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab0c8
 * (config/vtables.derived.base.txt, stored by FUN_00510cc0 FUN_00510e10), 0x270 bytes
 * (`mov edi, 0x270` before operator new in its creator FUN_005109d0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00510cc0 is not written, and its fields are not traced. */
class Object016ab0c8 : public Object016b9108 /* derived name */
{
  public:
    Object016ab0c8(const Name &name); /* FUN_00510cc0 */
    virtual ~Object016ab0c8();

  private:
    u8 unknown24[0x24c];
};

#endif
