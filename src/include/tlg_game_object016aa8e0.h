/* src/include/tlg_game_object016aa8e0.h: the class whose vtable is at 0x16aa8e0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA8E0_H
#define TLG_GAME_OBJECT016AA8E0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aa8e0
 * (config/vtables.derived.base.txt, stored by FUN_004f3ad0 FUN_004f3df0), 0x550 bytes
 * (`mov edi, 0x550` before operator new in its creator FUN_004f3970),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_004f3ad0 is not written, and its fields are not traced. */
class Object016aa8e0 : public Object016b9108 /* derived name */
{
  public:
    Object016aa8e0(const Name &name); /* FUN_004f3ad0 */
    virtual ~Object016aa8e0();

  private:
    u8 unknown24[0x52c];
};

#endif
