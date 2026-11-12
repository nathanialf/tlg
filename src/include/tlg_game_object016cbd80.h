/* src/include/tlg_game_object016cbd80.h: the class whose vtable is at
 * 0x16cbd80, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016CBD80_H
#define TLG_GAME_OBJECT016CBD80_H

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbd80
 * (config/vtables.derived.base.txt, stored by FUN_007ae5c0 FUN_0136cbe0 FUN_0136cd30 and 4 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136d120 tears them down
 * (the Names at +0x84, +0x80); the rest are not traced. */
class Object016cbd80 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cbd80();

  private:
    u8 unknown24[0x5c];
    Name name80; /* +0x80: released by the destructor (`mov eax, [rbx+0x80]; shl 5`) */
    Name name84; /* +0x84: released by the destructor (`mov eax, [rbx+0x84]; shl 5`) */
};

#endif
