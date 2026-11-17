/* src/include/tlg_game_object016cc1b8.h: the class whose vtable is at 0x16cc1b8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC1B8_H
#define TLG_GAME_OBJECT016CC1B8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc1b8
 * (config/vtables.derived.base.txt, stored by its creator FUN_0086e7f0, where
 * its constructor is inlined, and by its destructors 0x1372030 and
 * 0x1372160, not written), derived from Object016b9108. 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its fields are traced only
 * where the creator sets them. */
class Object016cc1b8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, then
     * zero at +0x24, +0x28 and +0x2c */
    Object016cc1b8(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown2c(0)
    {
    }

    virtual ~Object016cc1b8();

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    int unknown28; /* +0x28: 0 from the constructor */
    int unknown2c; /* +0x2c: 0 from the constructor */
};

#endif
