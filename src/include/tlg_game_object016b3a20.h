/* src/include/tlg_game_object016b3a20.h: the class whose vtable is at
 * 0x16b3a20 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B3A20_H
#define TLG_GAME_OBJECT016B3A20_H

#include "tlg_game_object016b39e8.h"

/* derived names: the class whose vtable is at 0x16b3a20
 * (config/vtables.derived.base.txt, stored by FUN_00ad5c50 FUN_00ad5e20
 * FUN_00ad5ee0), derived from Object016b39e8. 0x60 bytes (`mov edi, 0x60`
 * before operator new in the creator): no field of its own. Its destructor
 * (FUN_00ad5e20, a loop over the reference's records before the base's
 * destructor) is not written, so nothing here emits the vtable. */
class Object016b3a20 : public Object016b39e8 /* derived name */
{
  public:
    /* inlined in the creator: the base built, then the vptr */
    Object016b3a20(const Name &name) : Object016b39e8(name) {}

    virtual ~Object016b3a20();
};

#endif
