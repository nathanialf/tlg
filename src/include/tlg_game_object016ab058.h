/* src/include/tlg_game_object016ab058.h: the class whose vtable is at 0x16ab058
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB058_H
#define TLG_GAME_OBJECT016AB058_H

#include "tlg_game_name.h"
#include "tlg_game_object016aea40.h"

/* derived names: the class whose vtable is at 0x16ab058
 * (config/vtables.derived.base.txt, stored by its creator FUN_00510870, where
 * its constructor is inlined), derived from Object016aea40 (its constructor's stores
 * come first in the creator, the base's vptr store dead). 0x250 bytes
 * (`mov edi, 0x250` before operator new in the creator). Its fields are
 * traced only where the creator sets them; its destructor is not written. */
class Object016ab058 : public Object016aea40 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then nothing of its own */
    Object016ab058(const Name &name) : Object016aea40(name) {}

    virtual ~Object016ab058();
};

#endif
