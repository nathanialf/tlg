/* src/include/tlg_game_object016aae78.h: the class whose vtable is at 0x16aae78
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAE78_H
#define TLG_GAME_OBJECT016AAE78_H

#include "tlg_game_name.h"
#include "tlg_game_object016aea40.h"

/* derived names: the class whose vtable is at 0x16aae78
 * (config/vtables.derived.base.txt, stored by its creator FUN_0050b980, where
 * its constructor is inlined), derived from Object016aea40 (its constructor's stores
 * come first in the creator, the base's vptr store dead). 0x250 bytes
 * (`mov edi, 0x250` before operator new in the creator). Its fields are
 * traced only where the creator sets them; its destructor is not written. */
class Object016aae78 : public Object016aea40 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then nothing of its own */
    Object016aae78(const Name &name) : Object016aea40(name) {}

    virtual ~Object016aae78();
};

#endif
