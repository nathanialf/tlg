/* src/include/tlg_game_object016a8dd8.h: the class whose vtable is at 0x16a8dd8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8DD8_H
#define TLG_GAME_OBJECT016A8DD8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8dd8
 * (config/vtables.derived.base.txt, stored by FUN_0037e6a0 FUN_0037e960), 0x210 bytes
 * (`mov edi, 0x210` before operator new in its creator FUN_0037d990),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0037e6a0 is not written, and its fields are not traced. */
class Object016a8dd8 : public Object016b9108 /* derived name */
{
  public:
    Object016a8dd8(const Name &name); /* FUN_0037e6a0 */
    virtual ~Object016a8dd8();

  private:
    u8 unknown24[0x1ec];
};

#endif
