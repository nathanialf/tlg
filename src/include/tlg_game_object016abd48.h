/* src/include/tlg_game_object016abd48.h: the class whose vtable is at 0x16abd48
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ABD48_H
#define TLG_GAME_OBJECT016ABD48_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16abd48
 * (config/vtables.derived.base.txt, stored by FUN_006071a0 FUN_00608580), 0x1230 bytes
 * (`mov edi, 0x1230` before operator new in its creator FUN_005f3810),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_006071a0 is not written, and its fields are not traced. */
class Object016abd48 : public Object016b9108 /* derived name */
{
  public:
    Object016abd48(const Name &name); /* FUN_006071a0 */
    virtual ~Object016abd48();

  private:
    u8 unknown24[0x120c];
};

#endif
