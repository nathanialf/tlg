/* src/include/tlg_game_object016b2d10.h: the class whose vtable is at
 * 0x16b2d10 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B2D10_H
#define TLG_GAME_OBJECT016B2D10_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b2d10
 * (config/vtables.derived.base.txt, stored by FUN_00a9a7e0 FUN_00a9a9a0
 * FUN_00a9aae0), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a9a7e0 sets them and its destructor FUN_00a9a9a0
 * tears them down. The destructor is the class's key function
 * (leaf_00a9a9a0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b2d10 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, `vmovdqu [r15+0x40], xmm0`) with its
     * owner index from the thread's heap and its state */
    Object016b2d10(const Name &name) : Object016b9108(name) {}

    virtual ~Object016b2d10();

  private:
    Array01343a80<Name> names28; /* +0x28: an array of Names, each released by the destructor */
    Array01343a80<Ref00503fb0<Object016b9108>> record40; /* +0x40: an array of counted references */
};

#endif
