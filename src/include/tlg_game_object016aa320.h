/* src/include/tlg_game_object016aa320.h: the class whose vtable is at 0x16aa320
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA320_H
#define TLG_GAME_OBJECT016AA320_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aa320
 * (config/vtables.derived.base.txt, stored by FUN_004b7d80 FUN_004b8390), 0x5f0 bytes
 * (`mov edi, 0x5f0` before operator new in its creator FUN_004b7c20),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_004b7d80 is not written, and its fields are not traced. */
class Object016aa320 : public Object016b9108 /* derived name */
{
  public:
    Object016aa320(const Name &name); /* FUN_004b7d80 */
    virtual ~Object016aa320();

  private:
    u8 unknown24[0x5cc];
};

#endif
