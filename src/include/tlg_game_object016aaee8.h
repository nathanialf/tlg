/* src/include/tlg_game_object016aaee8.h: the class whose vtable is at 0x16aaee8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAEE8_H
#define TLG_GAME_OBJECT016AAEE8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aaee8
 * (config/vtables.derived.base.txt, stored by FUN_0050c1b0 FUN_0050c410), 0x290 bytes
 * (`mov edi, 0x290` before operator new in its creator FUN_0050bae0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0050c1b0 is not written, and its fields are not traced. */
class Object016aaee8 : public Object016b9108 /* derived name */
{
  public:
    Object016aaee8(const Name &name); /* FUN_0050c1b0 */
    virtual ~Object016aaee8();

  private:
    u8 unknown24[0x26c];
};

#endif
