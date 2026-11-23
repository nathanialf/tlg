/* src/include/tlg_game_object016cd468.h: the class whose vtable is at
 * 0x16cd468 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD468_H
#define TLG_GAME_OBJECT016CD468_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd468
 * (config/vtables.derived.base.txt, stored by FUN_009954c0 FUN_013832d0
 * FUN_01383370), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009954c0 sets them and its destructor FUN_013832d0
 * tears them down.
 * The destructor is implicit: FUN_013832d0 and the deleting
 * FUN_01383370 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_009954c0.cpp) emits the vtable
 * with both. */
class Object016cd468 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, `vmovdqu [r15+0x40], xmm0`) with its
     * owner index from the thread's heap and its state */
    Object016cd468(const Name &name) : Object016b9108(name) {}

  private:
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    Array01343a80<Ref00503fb0<Object016b9108>> record40; /* +0x40: an array of counted references */
};

#endif
