/* src/include/tlg_game_object016a9328.h: the class whose vtable is at
 * 0x16a9328 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9328_H
#define TLG_GAME_OBJECT016A9328_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9328
 * (config/vtables.derived.base.txt, stored by FUN_003ebf60 FUN_003ec8f0
 * FUN_003ec990), derived from Object016b9108: slots 5 to 9 are its own
 * (FUN_003eca30, FUN_003eca70, FUN_003ecac0, FUN_003ecb10, FUN_003ecb60; declared, not traced). 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_003ebf60 sets them and its destructor FUN_003ec8f0
 * tears them down. The destructor is the class's key function
 * (leaf_003ec8f0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016a9328 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state */
    Object016a9328(const Name &name) : Object016b9108(name) {}

    virtual ~Object016a9328();
    virtual void slot5(); /* derived name; FUN_003eca30, not traced */
    virtual void slot6(); /* derived name; FUN_003eca70, not traced */
    virtual void slot7(); /* derived name; FUN_003ecac0, not traced */
    virtual void slot8(); /* derived name; FUN_003ecb10, not traced */
    virtual void slot9(); /* derived name; FUN_003ecb60, not traced */

  private:
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
};

#endif
