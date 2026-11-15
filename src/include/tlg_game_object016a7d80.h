/* src/include/tlg_game_object016a7d80.h: the class whose vtable is at
 * 0x16a7d80 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7D80_H
#define TLG_GAME_OBJECT016A7D80_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7d80
 * (config/vtables.derived.base.txt, stored by FUN_002a8c50 FUN_002a8e10
 * FUN_002a8eb0), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_002a8c50 sets them and its destructor FUN_002a8e10
 * tears them down. The destructor is the class's key function
 * (leaf_002a8e10.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016a7d80 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, `vmovdqu [r15+0x40], xmm0`) with its
     * owner index from the thread's heap and its state, then the body's `mov
     * dword [r15+0x24], 0` */
    Object016a7d80(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0;
    }

    virtual ~Object016a7d80();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
    Array01343a80<Ref00503fb0<Node00503fb0>> record40; /* +0x40: an array of counted references */
};

#endif
