/* src/include/tlg_game_object016aad50.h: the class whose vtable is at 0x16aad50
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAD50_H
#define TLG_GAME_OBJECT016AAD50_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aad50
 * (config/vtables.derived.base.txt, stored by FUN_005073e0 FUN_005077d0), 0x190 bytes
 * (`mov edi, 0x190` before operator new in its creator FUN_00507280),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_005073e0 is not written, and its fields are not traced. */
class Object016aad50 : public Object016b9108 /* derived name */
{
  public:
    Object016aad50(const Name &name); /* FUN_005073e0 */
    virtual ~Object016aad50();

  private:
    u8 unknown24[0x16c];
};

#endif
