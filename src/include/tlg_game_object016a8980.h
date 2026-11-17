/* src/include/tlg_game_object016a8980.h: the class whose vtable is at 0x16a8980
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8980_H
#define TLG_GAME_OBJECT016A8980_H

#include "tlg_game_name.h"
#include "tlg_game_object016aeab0.h"

/* derived names: the class whose vtable is at 0x16a8980
 * (config/vtables.derived.base.txt, stored by its creator FUN_0035b210, where
 * its constructor is inlined), derived from Object016aeab0 (its constructor's stores
 * come first in the creator, the base's vptr store dead). 0x260 bytes
 * (`mov edi, 0x260` before operator new in the creator). Its fields are
 * traced only where the creator sets them; its destructor is not written. */
class Object016a8980 : public Object016aeab0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then nothing of its own */
    Object016a8980(const Name &name) : Object016aeab0(name) {}

    virtual ~Object016a8980();
};

#endif
