/* src/include/tlg_game_object016ab140.h: the class whose vtable is at 0x16ab140
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB140_H
#define TLG_GAME_OBJECT016AB140_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab140
 * (config/vtables.derived.base.txt, stored by FUN_00510fa0), 0x2a0 bytes
 * (`mov edi, 0x2a0` before operator new in its creator FUN_00510b30),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00510fa0 is not written, and its fields are not traced. */
class Object016ab140 : public Object016b9108 /* derived name */
{
  public:
    Object016ab140(const Name &name); /* FUN_00510fa0 */
    virtual ~Object016ab140();

  private:
    u8 unknown24[0x27c];
};

#endif
