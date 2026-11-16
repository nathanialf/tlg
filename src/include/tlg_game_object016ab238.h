/* src/include/tlg_game_object016ab238.h: the class whose vtable is at 0x16ab238
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB238_H
#define TLG_GAME_OBJECT016AB238_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab238
 * (config/vtables.derived.base.txt, stored by FUN_00525530 FUN_00526520), 0x4e40 bytes
 * (`mov edi, 0x4e40` before operator new in its creator FUN_00522f20),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00525530 is not written, and its fields are not traced. */
class Object016ab238 : public Object016b9108 /* derived name */
{
  public:
    Object016ab238(const Name &name); /* FUN_00525530 */
    virtual ~Object016ab238();

  private:
    u8 unknown24[0x4e1c];
};

#endif
