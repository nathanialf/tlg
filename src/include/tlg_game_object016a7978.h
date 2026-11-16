/* src/include/tlg_game_object016a7978.h: the class whose vtable is at 0x16a7978
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7978_H
#define TLG_GAME_OBJECT016A7978_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7978
 * (config/vtables.derived.base.txt, stored by FUN_0022f260 FUN_0022fd60), 0x670 bytes
 * (`mov edi, 0x670` before operator new in its creator FUN_00228d90),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0022f260 is not written, and its fields are not traced. */
class Object016a7978 : public Object016b9108 /* derived name */
{
  public:
    Object016a7978(const Name &name); /* FUN_0022f260 */
    virtual ~Object016a7978();

  private:
    u8 unknown24[0x64c];
};

#endif
