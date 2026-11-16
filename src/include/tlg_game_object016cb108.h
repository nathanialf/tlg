/* src/include/tlg_game_object016cb108.h: the class whose vtable is at 0x16cb108
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB108_H
#define TLG_GAME_OBJECT016CB108_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb108
 * (config/vtables.derived.base.txt, stored by FUN_013589f0 FUN_01358d70), 0x188 bytes
 * (`mov edi, 0x188` before operator new in its creator FUN_005ab9e0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_013589f0 is not written, and its fields are not traced. */
class Object016cb108 : public Object016b9108 /* derived name */
{
  public:
    Object016cb108(const Name &name); /* FUN_013589f0 */
    virtual ~Object016cb108();

  private:
    u8 unknown24[0x164];
};

#endif
