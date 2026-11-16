/* src/include/tlg_game_object016a9ba8.h: the class whose vtable is at 0x16a9ba8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9BA8_H
#define TLG_GAME_OBJECT016A9BA8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9ba8
 * (config/vtables.derived.base.txt, stored by FUN_00471620 FUN_00471830), 0x530 bytes
 * (`mov edi, 0x530` before operator new in its creator FUN_004714c0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00471620 is not written, and its fields are not traced. */
class Object016a9ba8 : public Object016b9108 /* derived name */
{
  public:
    Object016a9ba8(const Name &name); /* FUN_00471620 */
    virtual ~Object016a9ba8();

  private:
    u8 unknown24[0x50c];
};

#endif
