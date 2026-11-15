/* src/include/tlg_game_object016cd388.h: the class whose vtable is at
 * 0x16cd388 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD388_H
#define TLG_GAME_OBJECT016CD388_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd388
 * (config/vtables.derived.base.txt, stored by FUN_00991780 FUN_01387c30
 * FUN_01387d00), derived from Object016b9108. 0x90 bytes (`mov edi,
 * 0x90` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00991780 sets them and its destructor FUN_01387c30
 * tears them down. The destructor is the class's key function
 * (leaf_01387c30.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cd388 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 48 bytes from +0x30
     * cleared by two 32-byte stores that overlap, the last one first (eight
     * ints and the array's block, count and capacity: a run of zero stores
     * made one memset), the array's owner index from the thread's heap and its
     * state, then the 20 bytes from +0x70 (`vmovups [r15+0x70], xmm0; mov
     * dword [r15+0x80], 0`: five ints) */
    Object016cd388(const Name &name)
        : Object016b9108(name), unknown30(0), unknown34(0), unknown38(0), unknown3c(0),
          unknown40(0), unknown44(0), unknown48(0), unknown4c(0), unknown70(0), unknown74(0),
          unknown78(0), unknown7c(0), unknown80(0)
    {
    }

    virtual ~Object016cd388();

  private:
    u8 unknown24[0xc];
    int unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown34; /* +0x34: zero from the constructor; not traced */
    int unknown38; /* +0x38: zero from the constructor; not traced */
    int unknown3c; /* +0x3c: zero from the constructor; not traced */
    int unknown40; /* +0x40: zero from the constructor; not traced */
    int unknown44; /* +0x44: zero from the constructor; not traced */
    int unknown48; /* +0x48: zero from the constructor; not traced */
    int unknown4c; /* +0x4c: zero from the constructor; not traced */
    /* +0x50: an array whose elements need no destructor: the destructor
     * only releases its block */
    Array01343a80<u32> array50;
    u8 unknown68[0x8];
    int unknown70; /* +0x70: zero from the constructor; not traced */
    int unknown74; /* +0x74: zero from the constructor; not traced */
    int unknown78; /* +0x78: zero from the constructor; not traced */
    int unknown7c; /* +0x7c: zero from the constructor; not traced */
    int unknown80; /* +0x80: zero from the constructor; not traced */
    u8 unknown84[0xc];
};

#endif
