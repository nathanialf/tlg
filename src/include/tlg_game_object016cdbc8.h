/* src/include/tlg_game_object016cdbc8.h: the class whose vtable is at
 * 0x16cdbc8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDBC8_H
#define TLG_GAME_OBJECT016CDBC8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdbc8
 * (config/vtables.derived.base.txt, stored by FUN_009b55d0 FUN_013862f0
 * FUN_01386390), derived from Object016b9108. 0x80 bytes (`mov edi,
 * 0x80` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b55d0 sets them and its destructor FUN_013862f0
 * tears them down. The destructor is the class's key function
 * (leaf_013862f0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cdbc8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the four floats at +0x30
     * from the constants at 0x153b420 (0.4, 0.2, 0.4, 1) in one store, the two
     * arrays, each cleared (`vmovups [r15+0x40], xmm0`, `vmovups [r15+0x58],
     * xmm0`) with its owner index from the thread's heap and its state, `mov
     * dword [r15+0x70], 0` */
    Object016cdbc8(const Name &name)
        : Object016b9108(name), unknown30(0.4f), unknown34(0.2f), unknown38(0.4f), unknown3c(1.0f),
          unknown70(0)
    {
    }

    virtual ~Object016cdbc8();

  private:
    u8 unknown24[0xc];
    float unknown30; /* +0x30: 0.4 from the constructor; not traced */
    float unknown34; /* +0x34: 0.2 from the constructor; not traced */
    float unknown38; /* +0x38: 0.4 from the constructor; not traced */
    float unknown3c; /* +0x3c: 1.0 from the constructor; not traced */
    Array01343a80<Ref00503fb0<Node00503fb0>> record40; /* +0x40: an array of counted references */
    Array01343a80<Ref00503fb0<Node00503fb0>> record58; /* +0x58: an array of counted references */
    int unknown70; /* +0x70: zero from the constructor; not traced */
    u8 unknown74[0xc];
};

#endif
