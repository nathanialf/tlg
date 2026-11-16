/* src/include/tlg_game_object016c7368.h: the class whose vtable is at 0x16c7368
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7368_H
#define TLG_GAME_OBJECT016C7368_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7368
 * (config/vtables.derived.base.txt, stored by FUN_0029b9c0 FUN_002e6de0 FUN_002e9ef0 and 40 more), 0x3b0 bytes
 * (`mov edi, 0x3b0` before operator new in its creator FUN_00297ae0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0029b9c0 is not written, and its fields are not traced. */
class Object016c7368 : public Object016b9108 /* derived name */
{
  public:
    Object016c7368(const Name &name); /* FUN_0029b9c0 */
    virtual ~Object016c7368();

  private:
    u8 unknown24[0x38c];
};

#endif
