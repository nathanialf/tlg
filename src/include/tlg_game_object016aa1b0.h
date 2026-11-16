/* src/include/tlg_game_object016aa1b0.h: the class whose vtable is at 0x16aa1b0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA1B0_H
#define TLG_GAME_OBJECT016AA1B0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aa1b0
 * (config/vtables.derived.base.txt, stored by FUN_004b16e0 FUN_004b1df0), 0x700 bytes
 * (`mov edi, 0x700` before operator new in its creator FUN_004b1580),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_004b16e0 is not written, and its fields are not traced. */
class Object016aa1b0 : public Object016b9108 /* derived name */
{
  public:
    Object016aa1b0(const Name &name); /* FUN_004b16e0 */
    virtual ~Object016aa1b0();

  private:
    u8 unknown24[0x6dc];
};

#endif
