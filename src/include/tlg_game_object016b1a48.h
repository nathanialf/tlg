/* src/include/tlg_game_object016b1a48.h: the class whose vtable is at
 * 0x16b1a48 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1A48_H
#define TLG_GAME_OBJECT016B1A48_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b1a48
 * (config/vtables.derived.base.txt, stored by FUN_009f6ce0 FUN_009f88d0
 * FUN_009f8a70), derived from Object01343880. 0x90 bytes (`mov edi,
 * 0x90` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009f6ce0 sets them and its destructor FUN_009f88d0
 * tears them down. The destructor is the class's key function
 * (leaf_009f88d0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b1a48 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [rbx+0x34], 0`,
     * the four floats at +0x38 from the constants at 0x153b900 (0.1, 1.5, 5, 2)
     * in one store, the 24 bytes from +0x48 cleared (`vmovups [rbx+0x48],
     * xmm0; mov qword [rbx+0x58], 0`: the reference and two pointers, a run of
     * zero stores made one memset), the four floats at +0x60 from 0x153b910
     * (-1, 0, 0, 1), `mov dword [rbx+0x70], 0`, 0.01 at +0x74 and +0x78, `mov
     * byte [rbx+0x7c], 0`, `mov qword [rbx+0x80], 0` */
    Object016b1a48(const Name &name)
        : Object01343880(name), unknown34(0), unknown38(0.1f), unknown3c(1.5f), unknown40(5.0f),
          unknown44(2.0f), unknown50(0), unknown58(0), unknown60(-1.0f), unknown64(0.0f),
          unknown68(0.0f), unknown6c(1.0f), unknown70(0), unknown74(0.01f), unknown78(0.01f),
          unknown7c(false)
    {
    }

    virtual ~Object016b1a48();

  private:
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 0.1 from the constructor; not traced */
    float unknown3c; /* +0x3c: 1.5 from the constructor; not traced */
    float unknown40; /* +0x40: 5.0 from the constructor; not traced */
    float unknown44; /* +0x44: 2.0 from the constructor; not traced */
    /* +0x48: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held48;
    void *unknown50; /* +0x50: null from the constructor; not traced */
    void *unknown58; /* +0x58: null from the constructor; not traced */
    float unknown60; /* +0x60: -1.0 from the constructor; not traced */
    float unknown64; /* +0x64: zero from the constructor; not traced */
    float unknown68; /* +0x68: zero from the constructor; not traced */
    float unknown6c; /* +0x6c: 1.0 from the constructor; not traced */
    int unknown70;   /* +0x70: zero from the constructor; not traced */
    float unknown74; /* +0x74: 0.01 from the constructor; not traced */
    float unknown78; /* +0x78: 0.01 from the constructor; not traced */
    bool unknown7c;  /* +0x7c: false from the constructor; not traced */
    /* +0x80: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held80;
    u8 unknown88[0x8];
};

#endif
