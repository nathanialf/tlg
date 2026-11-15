/* src/include/tlg_game_object016d1c00.h: the class whose vtable is at
 * 0x16d1c00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1C00_H
#define TLG_GAME_OBJECT016D1C00_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d1c00
 * (config/vtables.derived.base.txt, stored by FUN_00cd5ae0 FUN_013af6d0
 * FUN_013af7e0), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00cd5ae0 sets them and its destructor FUN_013af6d0
 * tears them down. The destructor is the class's key function
 * (leaf_013af6d0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016d1c00 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, `vmovdqu [r15+0x40], xmm0`) with its
     * owner index from the thread's heap and its state */
    Object016d1c00(const Name &name) : Object016b9108(name) {}

    virtual ~Object016d1c00();

  private:
    /* +0x28 and +0x40: arrays whose elements need no destructor: the
     * destructor only releases their blocks */
    Array01343a80<u32> array28;
    Array01343a80<u32> array40;
};

#endif
