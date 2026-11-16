/* src/include/tlg_game_object016a80b0.h: the class whose vtable is at 0x16a80b0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A80B0_H
#define TLG_GAME_OBJECT016A80B0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a80b0
 * (config/vtables.derived.base.txt, stored by FUN_002bfd90 FUN_002bff40), 0x270 bytes
 * (`mov edi, 0x270` before operator new in its creator FUN_002bfc20),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002bfd90 is not written, and its fields are not traced. */
class Object016a80b0 : public Object016b9108 /* derived name */
{
  public:
    Object016a80b0(const Name &name); /* FUN_002bfd90 */
    virtual ~Object016a80b0();

  private:
    u8 unknown24[0x24c];
};

#endif
