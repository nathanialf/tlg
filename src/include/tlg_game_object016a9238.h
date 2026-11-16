/* src/include/tlg_game_object016a9238.h: the class whose vtable is at 0x16a9238
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9238_H
#define TLG_GAME_OBJECT016A9238_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9238
 * (config/vtables.derived.base.txt, stored by FUN_003e7b30 FUN_003e7ca0), 0xc0 bytes
 * (`mov edi, 0xc0` before operator new in its creator FUN_003e79d0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_003e7b30 is not written, and its fields are not traced. */
class Object016a9238 : public Object016b9108 /* derived name */
{
  public:
    Object016a9238(const Name &name); /* FUN_003e7b30 */
    virtual ~Object016a9238();

  private:
    u8 unknown24[0x9c];
};

#endif
