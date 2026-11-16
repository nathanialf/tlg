/* src/include/tlg_game_object016ab5d0.h: the class whose vtable is at 0x16ab5d0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB5D0_H
#define TLG_GAME_OBJECT016AB5D0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab5d0
 * (config/vtables.derived.base.txt, stored by FUN_00547030 FUN_0054cdd0), 0x5f0 bytes
 * (`mov edi, 0x5f0` before operator new in its creator FUN_00537c70),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00547030 is not written, and its fields are not traced. */
class Object016ab5d0 : public Object016b9108 /* derived name */
{
  public:
    Object016ab5d0(const Name &name); /* FUN_00547030 */
    virtual ~Object016ab5d0();

  private:
    u8 unknown24[0x5cc];
};

#endif
