/* src/include/tlg_game_object016aaf60.h: the class whose vtable is at 0x16aaf60
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAF60_H
#define TLG_GAME_OBJECT016AAF60_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aaf60
 * (config/vtables.derived.base.txt, stored by FUN_00510130), 0x2a0 bytes
 * (`mov edi, 0x2a0` before operator new in its creator FUN_0050bc40),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00510130 is not written, and its fields are not traced. */
class Object016aaf60 : public Object016b9108 /* derived name */
{
  public:
    Object016aaf60(const Name &name); /* FUN_00510130 */
    virtual ~Object016aaf60();

  private:
    u8 unknown24[0x27c];
};

#endif
