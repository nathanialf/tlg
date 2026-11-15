/* src/include/tlg_game_object016cc2d0.h: the class whose vtable is at
 * 0x16cc2d0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC2D0_H
#define TLG_GAME_OBJECT016CC2D0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc2d0
 * (config/vtables.derived.base.txt, stored by FUN_008791f0 FUN_01373420
 * FUN_01373550), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008791f0 sets them and its destructor FUN_01373420
 * tears them down. The destructor is the class's key function
 * (leaf_01373420.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cc2d0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its lock, `mov qword [r15+0x40], 0` */
    Object016cc2d0(const Name &name) : Object016b9108(name), unknown40(0) {}

    virtual ~Object016cc2d0();

  private:
    u8 unknown24[0x4];
    Array01343a80<Name> names28; /* +0x28: an array of Names, each released by the destructor */
    void *unknown40;             /* +0x40: null from the constructor; not traced */
};

#endif
