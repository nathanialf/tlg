/* src/include/tlg_game_object016a8910.h: the class whose vtable is at 0x16a8910
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8910_H
#define TLG_GAME_OBJECT016A8910_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016aea40.h"

/* derived names: the class whose vtable is at 0x16a8910
 * (config/vtables.derived.base.txt, stored by its creator FUN_0035b0a0, where
 * its constructor is inlined), derived from Object016aea40 (its constructor's stores
 * come first in the creator, the base's vptr store dead). 0x260 bytes
 * (`mov edi, 0x260` before operator new in the creator). Its fields are
 * traced only where the creator sets them; its destructor is not written. */
class Object016a8910 : public Object016aea40 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then 2.0 at +0x248 and zero at +0x24c and +0x250 (one eight-byte store) */
    Object016a8910(const Name &name)
        : Object016aea40(name), unknown248(2.0f), unknown24c(0), unknown250(0)
    {
    }

    virtual ~Object016a8910();

  private:
    float unknown248; /* +0x248: 2.0 from the constructor */
    int unknown24c;   /* +0x24c: 0 from the constructor */
    int unknown250;   /* +0x250: 0 from the constructor */
};

#endif
