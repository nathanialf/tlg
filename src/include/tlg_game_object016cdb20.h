/* src/include/tlg_game_object016cdb20.h: the class whose vtable is at
 * 0x16cdb20 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDB20_H
#define TLG_GAME_OBJECT016CDB20_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdb20
 * (config/vtables.derived.base.txt, stored by FUN_009b4db0 FUN_01386740
 * FUN_013867e0), derived from Object016b9108. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b4db0 sets them and its destructor FUN_01386740
 * tears them down. The destructor is the class's key function
 * (leaf_01386740.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cdb20 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, `vmovdqu [r15+0x40], xmm0`) with its
     * owner index from the thread's heap and its state, 2.0 at +0x58 */
    Object016cdb20(const Name &name) : Object016b9108(name), unknown58(2.0f) {}

    virtual ~Object016cdb20();

  private:
    u8 unknown24[0x4];
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
    Array01343a80<Ref00503fb0<Node00503fb0>> record40; /* +0x40: an array of counted references */
    float unknown58; /* +0x58: 2.0 from the constructor; not traced */
    u8 unknown5c[0x4];
};

#endif
