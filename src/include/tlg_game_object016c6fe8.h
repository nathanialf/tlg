/* src/include/tlg_game_object016c6fe8.h: the class whose vtable is at 0x16c6fe8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C6FE8_H
#define TLG_GAME_OBJECT016C6FE8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c6fe8
 * (config/vtables.base.txt, stored by 0x1bba90; its constructor
 * is inlined in its creator FUN_001bba90), derived from Object016b9108 (the creator calls
 * that class's constructor 0xcb6310 first). 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its fields are traced only
 * where the creator sets them; its destructor is not written. */
class Object016c6fe8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, -1 at +0x24 and 0 at +0x28 (one eight-byte store) */
    Object016c6fe8(const Name &name) : Object016b9108(name), unknown24(-1), unknown28(0) {}

    virtual ~Object016c6fe8();

  private:
    int unknown24; /* +0x24: -1 from the constructor */
    int unknown28; /* +0x28: 0 from the constructor */
    u8 unknown2c[0x4];
};

#endif
