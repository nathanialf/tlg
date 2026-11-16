/* src/include/tlg_game_object016a9a38.h: the class whose vtable is at 0x16a9a38
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9A38_H
#define TLG_GAME_OBJECT016A9A38_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9a38
 * (config/vtables.derived.base.txt, stored by FUN_0042dd90 FUN_0042e5e0), 0x1840 bytes
 * (`mov edi, 0x1840` before operator new in its creator FUN_0042dc30),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0042dd90 is not written, and its fields are not traced. */
class Object016a9a38 : public Object016b9108 /* derived name */
{
  public:
    Object016a9a38(const Name &name); /* FUN_0042dd90 */
    virtual ~Object016a9a38();

  private:
    u8 unknown24[0x181c];
};

#endif
