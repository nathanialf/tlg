/* src/include/tlg_game_object016a8bc8.h: the class whose vtable is at 0x16a8bc8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8BC8_H
#define TLG_GAME_OBJECT016A8BC8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8bc8
 * (config/vtables.derived.base.txt, stored by FUN_0036c400 FUN_0036c7b0), 0x130 bytes
 * (`mov edi, 0x130` before operator new in its creator FUN_0036c2a0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0036c400 is not written, and its fields are not traced. */
class Object016a8bc8 : public Object016b9108 /* derived name */
{
  public:
    Object016a8bc8(const Name &name); /* FUN_0036c400 */
    virtual ~Object016a8bc8();

  private:
    u8 unknown24[0x10c];
};

#endif
