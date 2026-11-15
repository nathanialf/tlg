/* src/include/tlg_game_object016aea00.h: the class whose vtable is at
 * 0x16aea00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEA00_H
#define TLG_GAME_OBJECT016AEA00_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aea00
 * (config/vtables.derived.base.txt, stored by FUN_0081b070 FUN_0136fc40
 * FUN_0136fce0), derived from Object016b9108: slot 5 is its own
 * (FUN_0081e140; declared, not traced). 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_0081b070 sets them and its destructor FUN_0136fc40
 * tears them down. The destructor is the class's key function
 * (leaf_0136fc40.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016aea00 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state */
    Object016aea00(const Name &name) : Object016b9108(name) {}

    virtual ~Object016aea00();
    virtual void slot5(); /* derived name; FUN_0081e140, not traced */

  private:
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
};

#endif
