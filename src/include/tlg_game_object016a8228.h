/* src/include/tlg_game_object016a8228.h: the class whose vtable is at 0x16a8228
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8228_H
#define TLG_GAME_OBJECT016A8228_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8228
 * (config/vtables.derived.base.txt, stored by FUN_002e2940 FUN_002e2aa0), 0x440 bytes
 * (`mov edi, 0x440` before operator new in its creator FUN_002e27e0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002e2940 is not written, and its fields are not traced. */
class Object016a8228 : public Object016b9108 /* derived name */
{
  public:
    Object016a8228(const Name &name); /* FUN_002e2940 */
    virtual ~Object016a8228();

  private:
    u8 unknown24[0x41c];
};

#endif
