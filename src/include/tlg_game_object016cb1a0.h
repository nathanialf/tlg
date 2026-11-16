/* src/include/tlg_game_object016cb1a0.h: the class whose vtable is at 0x16cb1a0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB1A0_H
#define TLG_GAME_OBJECT016CB1A0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb1a0
 * (config/vtables.derived.base.txt, stored by FUN_005b05b0 FUN_005b14b0), 0x1ea0 bytes
 * (`mov edi, 0x1ea0` before operator new in its creator FUN_005abd00),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_005b05b0 is not written, and its fields are not traced. */
class Object016cb1a0 : public Object016b9108 /* derived name */
{
  public:
    Object016cb1a0(const Name &name); /* FUN_005b05b0 */
    virtual ~Object016cb1a0();

  private:
    u8 unknown24[0x1e7c];
};

#endif
