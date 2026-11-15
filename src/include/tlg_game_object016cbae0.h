/* src/include/tlg_game_object016cbae0.h: the class whose vtable is at
 * 0x16cbae0, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016CBAE0_H
#define TLG_GAME_OBJECT016CBAE0_H

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbae0
 * (config/vtables.derived.base.txt, stored by FUN_007ad260 FUN_0136e240 FUN_0136e390 and 4 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136e780 tears them down
 * (the Names at +0x94, +0x90) and where its creator FUN_007ad260 sets
 * them. 0xa0 bytes (`mov edi, 0xa0` before operator new in the creator). */
class Object016cbae0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in its creator FUN_007ad260: the base built from the name, the
     * vptr, the four floats at +0x30 from the constants at 0x1536e40 (0, 0, 0,
     * 1) in one store, `mov dword [rbx+0x40], 0`, the eight floats at +0x50
     * from the constants at 0x14e4b80 in one store, the largest negative float
     * twice from +0x70, the four floats at +0x78 from the constants at
     * 0x1536e50 in one store (the vectoriser's 16-store chunks: the chain from
     * +0x50 ends in the first chunk at +0x74, the second chunk's chain from
     * +0x78 is six floats), the largest float and 1.0 at +0x88, the two names
     * and the int at +0x98 cleared */
    Object016cbae0(const Name &name)
        : Object016b9108(name), unknown30(0.0f), unknown34(0.0f), unknown38(0.0f), unknown3c(1.0f),
          unknown40(0), unknown50(1.0f), unknown54(1.0f), unknown58(1.0f), unknown5c(1.0f),
          unknown60(0.0f), unknown64(0.0f), unknown68(0.0f), unknown6c(1.0f),
          unknown70(-3.40282347e+38f), unknown74(-3.40282347e+38f), unknown78(-3.40282347e+38f),
          unknown7c(1.0f), unknown80(3.40282347e+38f), unknown84(3.40282347e+38f),
          unknown88(3.40282347e+38f), unknown8c(1.0f), unknown98(0)
    {
    }

    virtual ~Object016cbae0();

  private:
    u8 unknown24[0xc];
    float unknown30; /* +0x30: zero from the constructor; not traced */
    float unknown34; /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: zero from the constructor; not traced */
    float unknown3c; /* +0x3c: 1.0 from the constructor; not traced */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    u8 unknown44[0xc];
    float unknown50; /* +0x50: 1.0 from the constructor; not traced */
    float unknown54; /* +0x54: 1.0 from the constructor; not traced */
    float unknown58; /* +0x58: 1.0 from the constructor; not traced */
    float unknown5c; /* +0x5c: 1.0 from the constructor; not traced */
    float unknown60; /* +0x60: zero from the constructor; not traced */
    float unknown64; /* +0x64: zero from the constructor; not traced */
    float unknown68; /* +0x68: zero from the constructor; not traced */
    float unknown6c; /* +0x6c: 1.0 from the constructor; not traced */
    float unknown70; /* +0x70: -FLT_MAX from the constructor; not traced */
    float unknown74; /* +0x74: -FLT_MAX from the constructor; not traced */
    float unknown78; /* +0x78: -FLT_MAX from the constructor; not traced */
    float unknown7c; /* +0x7c: 1.0 from the constructor; not traced */
    float unknown80; /* +0x80: FLT_MAX from the constructor; not traced */
    float unknown84; /* +0x84: FLT_MAX from the constructor; not traced */
    float unknown88; /* +0x88: FLT_MAX from the constructor; not traced */
    float unknown8c; /* +0x8c: 1.0 from the constructor; not traced */
    Name name90;     /* +0x90: released by the destructor (`mov eax, [rbx+0x90]; shl 5`) */
    Name name94;     /* +0x94: released by the destructor (`mov eax, [rbx+0x94]; shl 5`) */
    /* +0x98: zero from the constructor; not traced (the derived classes'
     * fields begin after it, at +0x9c) */
    int unknown98;
};

/* derived name: the complete destructor (slot 0 of 0x16cbae0, FUN_0136e780): the
 * body is empty; the two Names are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0136e880,
 * slot 1, is the deleting one. Defined here, inline: the destructors of the
 * derived classes hold this body, and with no key function the class's
 * vtable and its two destructors are emitted by a unit that stores the
 * vtable (leaf_0136e4e0.cpp, the row's unit). */
inline Object016cbae0::~Object016cbae0() {}

#endif
