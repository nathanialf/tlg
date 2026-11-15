/* src/include/tlg_game_object016cd5f0.h: the class whose vtable is at
 * 0x16cd5f0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD5F0_H
#define TLG_GAME_OBJECT016CD5F0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd5f0
 * (config/vtables.derived.base.txt, stored by FUN_009b3700 FUN_01386c00
 * FUN_01386d00), derived from Object016b9108. 0xa8 bytes (`mov edi,
 * 0xa8` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b3700 sets them and its destructor FUN_01386c00
 * tears them down. The destructor is the class's key function
 * (leaf_01386c00.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cd5f0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the name, 0.1, 0 and 0.3
     * (`mov qword [rbx+0x2c]` the last two), the int at +0x34 and the array's
     * block, count and capacity cleared (`vmovdqu [rbx+0x34], xmm0; mov dword
     * [rbx+0x44], 0`: a run of zero stores made one memset), its owner index and
     * state, then floats and ints alternating to +0xa4 (four 4-byte fields of
     * one type would be one vector store) */
    Object016cd5f0(const Name &name)
        : Object016b9108(name), unknown28(0.1f), unknown2c(0), unknown30(0.3f), unknown34(0),
          unknown50(10.0f), unknown54(0), unknown58(0.05f), unknown5c(0), unknown60(30),
          unknown64(40.0f), unknown68(0), unknown6c(0.25f), unknown70(0), unknown74(0.8f),
          unknown78(0), unknown7c(0.4f), unknown80(0), unknown84(0.25f), unknown88(0),
          unknown8c(20.0f), unknown90(0), unknown94(0), unknown98(0.01f), unknown9c(0),
          unknowna0(20.0f), unknowna4(0)
    {
    }

    virtual ~Object016cd5f0();

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    float unknown28; /* +0x28: 0.1 from the constructor; not traced */
    int unknown2c;   /* +0x2c: zero from the constructor; not traced */
    float unknown30; /* +0x30: 0.3 from the constructor; not traced */
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    /* +0x38: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x38]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array38;
    float unknown50; /* +0x50: 10.0 from the constructor; not traced */
    int unknown54;   /* +0x54: zero from the constructor; not traced */
    float unknown58; /* +0x58: 0.05 from the constructor; not traced */
    int unknown5c;   /* +0x5c: zero from the constructor; not traced */
    int unknown60;   /* +0x60: 30 from the constructor; not traced */
    float unknown64; /* +0x64: 40.0 from the constructor; not traced */
    int unknown68;   /* +0x68: zero from the constructor; not traced */
    float unknown6c; /* +0x6c: 0.25 from the constructor; not traced */
    int unknown70;   /* +0x70: zero from the constructor; not traced */
    float unknown74; /* +0x74: 0.8 from the constructor; not traced */
    int unknown78;   /* +0x78: zero from the constructor; not traced */
    float unknown7c; /* +0x7c: 0.4 from the constructor; not traced */
    int unknown80;   /* +0x80: zero from the constructor; not traced */
    float unknown84; /* +0x84: 0.25 from the constructor; not traced */
    int unknown88;   /* +0x88: zero from the constructor; not traced */
    float unknown8c; /* +0x8c: 20.0 from the constructor; not traced */
    int unknown90;   /* +0x90: zero from the constructor; not traced */
    int unknown94;   /* +0x94: zero from the constructor; not traced */
    float unknown98; /* +0x98: 0.01 from the constructor; not traced */
    int unknown9c;   /* +0x9c: zero from the constructor; not traced */
    float unknowna0; /* +0xa0: 20.0 from the constructor; not traced */
    int unknowna4;   /* +0xa4: zero from the constructor; not traced */
};

#endif
