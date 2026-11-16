/* src/include/tlg_game_object016a7f88.h: the class whose vtable is at 0x16a7f88
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7F88_H
#define TLG_GAME_OBJECT016A7F88_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7f88
 * (config/vtables.derived.base.txt, stored by FUN_002bbb10 FUN_002bbc70 FUN_002bbda0), 0x80 bytes
 * (`mov edi, 0x80` before operator new in its creator FUN_002bb9b0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002bbb10 is not written, and its fields are not traced. */
class Object016a7f88 : public Object016b9108 /* derived name */
{
  public:
    Object016a7f88(const Name &name); /* FUN_002bbb10 */
    virtual ~Object016a7f88();

  private:
    u8 unknown24[0x5c];
};

#endif
