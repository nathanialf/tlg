/* src/include/tlg_game_object016ab6b0.h: the class whose vtable is at 0x16ab6b0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB6B0_H
#define TLG_GAME_OBJECT016AB6B0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab6b0
 * (config/vtables.derived.base.txt, stored by FUN_0057c270), 0x1d0 bytes
 * (`mov edi, 0x1d0` before operator new in its creator FUN_0057c110),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0057c270 is not written, and its fields are not traced. */
class Object016ab6b0 : public Object016b9108 /* derived name */
{
  public:
    Object016ab6b0(const Name &name); /* FUN_0057c270 */
    virtual ~Object016ab6b0();

  private:
    u8 unknown24[0x1ac];
};

#endif
