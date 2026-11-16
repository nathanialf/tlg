/* src/include/tlg_game_object016b1928.h: the class whose vtable is at
 * 0x16b1928 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1928_H
#define TLG_GAME_OBJECT016B1928_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b1928
 * (config/vtables.derived.base.txt, stored by FUN_009b4670 FUN_01384ce0
 * FUN_01384e00), derived from Object016b9108: slots 5 and 6 are its own
 * (FUN_01384810, a body the linker folded with other classes'; FUN_009f37a0;
 * declared, their bodies are not written here). 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b4670 sets them and its destructor FUN_01384ce0
 * tears them down. The destructor is the class's key function
 * (leaf_01384ce0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b1928 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array
     * cleared (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's
     * heap and its state, `mov qword [r15+0x40], 0` */
    Object016b1928(const Name &name) : Object016b9108(name) {}

    virtual ~Object016b1928();
    virtual void slot5(); /* derived name; FUN_01384810, not traced */
    virtual void slot6(); /* derived name; FUN_009f37a0, not traced */

  private:
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    /* +0x40: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held40;
};

#endif
