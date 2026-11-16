/* src/include/tlg_game_object016aad98.h: the class whose vtable is at 0x16aad98
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAD98_H
#define TLG_GAME_OBJECT016AAD98_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aad98
 * (config/vtables.derived.base.txt, stored by FUN_00509f80 FUN_0050a0e0), 0x140 bytes
 * (`mov edi, 0x140` before operator new in its creator FUN_00509e20),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00509f80 is not written, and its fields are not traced. */
class Object016aad98 : public Object016b9108 /* derived name */
{
  public:
    Object016aad98(const Name &name); /* FUN_00509f80 */
    virtual ~Object016aad98();

  private:
    u8 unknown24[0x11c];
};

#endif
