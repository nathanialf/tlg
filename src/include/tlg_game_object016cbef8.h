/* src/include/tlg_game_object016cbef8.h: the class whose vtable is at 0x16cbef8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBEF8_H
#define TLG_GAME_OBJECT016CBEF8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbef8
 * (config/vtables.derived.base.txt, stored by its creator FUN_00806360, where
 * its constructor is inlined, and by its destructors 0x136f290 and 0x136f400,
 * not written), derived from Object016b9108. 0x40 bytes (`mov edi, 0x40`
 * before operator new in the creator). Its fields are traced only where the
 * creator sets them. */
class Object016cbef8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 0 at
     * +0x24, the array at +0x28 (its owner index from the thread's heap, its
     * lock free) */
    Object016cbef8(const Name &name) : Object016b9108(name), unknown24(0) {}

    virtual ~Object016cbef8();

  private:
    int unknown24;                 /* +0x24: 0 from the constructor */
    Array01343a80<void *> array28; /* +0x28: empty from the constructor; its elements not traced */
};

#endif
