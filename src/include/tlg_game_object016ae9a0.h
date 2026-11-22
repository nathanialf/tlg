/* src/include/tlg_game_object016ae9a0.h: the class whose vtable is at
 * 0x16ae9a0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE9A0_H
#define TLG_GAME_OBJECT016AE9A0_H

#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16ae9a0
 * (config/vtables.derived.base.txt, stored by FUN_0081af10 FUN_0081b9c0
 * FUN_0081baf0), derived from Object016b85e0. 0x260 bytes (`mov edi,
 * 0x260` before operator new in the creator). Its own fields are traced
 * where its creator FUN_0081af10 sets them and its destructor FUN_0081b9c0
 * tears them down. The destructor is the class's key function
 * (leaf_0081b9c0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016ae9a0 : public Object016b85e0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 32 bytes at +0x238
     * cleared in one store (`vmovups [r15+0x238], ymm0`: a pointer, the two
     * references and a pointer, a run of zero stores made one memset) */
    Object016ae9a0(const Name &name) : Object016b85e0(name), unknown238(0), unknown250(0) {}

    virtual ~Object016ae9a0();

  private:
    void *unknown238; /* +0x238: null from the constructor; not traced */
    /* +0x240: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held240;
    /* +0x248: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held248;
    void *unknown250; /* +0x250: null from the constructor; not traced */
    u8 unknown258[0x8];
};

#endif
