/* src/include/tlg_game_object016aaa40.h: the class whose vtable is at 0x16aaa40
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAA40_H
#define TLG_GAME_OBJECT016AAA40_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aaa40
 * (config/vtables.derived.base.txt, stored by FUN_00500940 FUN_00500bf0), 0x1a0 bytes
 * (`mov edi, 0x1a0` before operator new in its creator FUN_005007b0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00500940 is not written, and its fields are not traced. */
class Object016aaa40 : public Object016b9108 /* derived name */
{
  public:
    Object016aaa40(const Name &name); /* FUN_00500940 */
    virtual ~Object016aaa40();

  private:
    u8 unknown24[0x17c];
};

#endif
