/* src/include/tlg_game_object016cb040.h: the class whose vtable is at 0x16cb040
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB040_H
#define TLG_GAME_OBJECT016CB040_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb040
 * (config/vtables.derived.base.txt, stored by 0x52deb0 0x1358850; its constructor
 * is inlined in its creator FUN_0052deb0), derived from Object016b9108 (the creator calls
 * that class's constructor 0xcb6310 first). 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its fields are traced only
 * where the creator sets them; its destructor is not written. */
class Object016cb040 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the 16 bytes from +0x28 cleared in one store (`vmovdqu [r15+0x28], xmm0`) */
    Object016cb040(const Name &name) : Object016b9108(name), unknown28(0), unknown30(0) {}

    virtual ~Object016cb040();

  private:
    u8 unknown24[0x4];
    void *unknown28; /* +0x28: null from the constructor; not traced */
    void *unknown30; /* +0x30: null from the constructor; not traced */
    u8 unknown38[0x8];
};

#endif
