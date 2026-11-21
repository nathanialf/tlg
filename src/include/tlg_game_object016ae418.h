/* src/include/tlg_game_object016ae418.h: the class whose vtable is at
 * 0x16ae418 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE418_H
#define TLG_GAME_OBJECT016AE418_H

#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16ae418
 * (config/vtables.derived.base.txt, stored by FUN_0080aeb0 FUN_0080b5d0
 * FUN_0080b680), derived from Object016b85e0. 0x250 bytes (`mov edi,
 * 0x250` before operator new in the creator). Its own fields are traced
 * where its creator FUN_0080aeb0 sets them and its destructor FUN_0080b5d0
 * tears them down. The destructor is the class's key function
 * (leaf_0080b5d0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016ae418 : public Object016b85e0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 16 bytes at +0x238
     * cleared in one store (`vmovdqu [r15+0x238], xmm0`: the eight bytes before
     * the reference and the reference, a run of zero stores made one memset) */
    Object016ae418(const Name &name) : Object016b85e0(name), unknown238(0) {}

    virtual ~Object016ae418();

  private:
    u8 unknown24[0x214];
    void *unknown238; /* +0x238: null from the constructor; not traced */
    /* +0x240: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held240;
    u8 unknown248[0x8];
};

#endif
