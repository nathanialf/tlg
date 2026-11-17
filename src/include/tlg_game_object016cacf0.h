/* src/include/tlg_game_object016cacf0.h: the class whose vtable is at 0x16cacf0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CACF0_H
#define TLG_GAME_OBJECT016CACF0_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cacf0
 * (config/vtables.derived.base.txt, stored by 0x422e90 0x13508a0; its constructor
 * is inlined in its creator FUN_00422e90), derived from Object016b9108 (the creator calls
 * that class's constructor 0xcb6310 first). 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its fields are traced only
 * where the creator sets them; its destructor is not written. */
class Object016cacf0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the 16 bytes from +0x24 cleared in one store (`vmovdqu [r15+0x24], xmm0`) */
    Object016cacf0(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown2c(0), unknown30(0)
    {
    }

    virtual ~Object016cacf0();

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    int unknown28; /* +0x28: 0 from the constructor */
    int unknown2c; /* +0x2c: 0 from the constructor */
    int unknown30; /* +0x30: 0 from the constructor */
};

#endif
