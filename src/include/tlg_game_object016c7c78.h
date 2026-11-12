/* src/include/tlg_game_object016c7c78.h: the class whose vtable is at
 * 0x16c7c78, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016C7C78_H
#define TLG_GAME_OBJECT016C7C78_H

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7c78
 * (config/vtables.derived.base.txt, stored by FUN_00a29d80 FUN_00a29f30 FUN_00a2a290 and 4 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00a2a290 tears them down
 * (the Name at +0x24); the rest are not traced. */
class Object016c7c78 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c7c78();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
};

#endif
