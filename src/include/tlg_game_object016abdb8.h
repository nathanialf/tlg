/* src/include/tlg_game_object016abdb8.h: the class whose vtable is at
 * 0x16abdb8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ABDB8_H
#define TLG_GAME_OBJECT016ABDB8_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16abdb8
 * (config/vtables.derived.base.txt, stored by FUN_00617420 FUN_006175c0
 * FUN_006176b0), derived from Object01343880. 0x90 bytes (`mov edi,
 * 0x90` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00617420 sets them and its destructor FUN_006175c0
 * tears them down. The destructor is the class's key function
 * (leaf_006175c0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016abdb8 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x40], 0`
     * (the name), the 16 bytes at +0x50 cleared (four ints), 1.0 at +0x60, the
     * 24 bytes from +0x64 cleared (`vmovdqu [r15+0x64], xmm0; mov qword
     * [r15+0x74], 0`: five ints and the second name), 1.0 at +0x7c, `mov qword
     * [r15+0x80], 0`: each run of zero stores made one memset */
    Object016abdb8(const Name &name)
        : Object01343880(name), unknown50(0), unknown54(0), unknown58(0), unknown5c(0),
          unknown60(1.0f), unknown64(0), unknown68(0), unknown6c(0), unknown70(0), unknown74(0),
          unknown7c(1.0f), unknown80(0)
    {
    }

    virtual ~Object016abdb8();

  private:
    u8 unknown34[0xc];
    Name name40; /* +0x40: empty from the constructor, released by the destructor */
    u8 unknown44[0xc];
    int unknown50;   /* +0x50: zero from the constructor; not traced */
    int unknown54;   /* +0x54: zero from the constructor; not traced */
    int unknown58;   /* +0x58: zero from the constructor; not traced */
    int unknown5c;   /* +0x5c: zero from the constructor; not traced */
    float unknown60; /* +0x60: 1.0 from the constructor; not traced */
    int unknown64;   /* +0x64: zero from the constructor; not traced */
    int unknown68;   /* +0x68: zero from the constructor; not traced */
    int unknown6c;   /* +0x6c: zero from the constructor; not traced */
    int unknown70;   /* +0x70: zero from the constructor; not traced */
    int unknown74;   /* +0x74: zero from the constructor; not traced */
    Name name78;     /* +0x78: empty from the constructor, released by the destructor */
    float unknown7c; /* +0x7c: 1.0 from the constructor; not traced */
    void *unknown80; /* +0x80: null from the constructor; not traced */
    u8 unknown88[0x8];
};

#endif
