/* src/include/tlg_game_object016b03a8.h: the class whose vtable is at
 * 0x16b03a8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B03A8_H
#define TLG_GAME_OBJECT016B03A8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16b03a8
 * (config/vtables.derived.base.txt, stored by FUN_008e39f0 FUN_008e3b50
 * FUN_008e3c80), derived from Object016b85e0. 0x250 bytes (`mov edi,
 * 0x250` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008e39f0 sets them and its destructor FUN_008e3b50
 * tears them down. The destructor is the class's key function
 * (leaf_008e3b50.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b03a8 : public Object016b85e0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 16 bytes at +0x238
     * cleared in one store (`vmovdqu [r15+0x238], xmm0`: the two references) */
    Object016b03a8(const Name &name) : Object016b85e0(name) {}

    virtual ~Object016b03a8();

  private:
    u8 unknown8[0x230];
    /* +0x238: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held238;
    /* +0x240: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held240;
    u8 unknown248[0x8];
};

#endif
