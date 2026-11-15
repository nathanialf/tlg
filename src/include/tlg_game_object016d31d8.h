/* src/include/tlg_game_object016d31d8.h: the class whose vtable is at
 * 0x16d31d8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D31D8_H
#define TLG_GAME_OBJECT016D31D8_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_math.h"
#include "tlg_game_object00ccfd00.h"

/* derived names: the class whose vtable is at 0x16d31d8
 * (config/vtables.derived.base.txt, stored by FUN_00e90cb0 FUN_013cbb40 FUN_013cbbf0), derived from
 * Object00ccfd00 (the class whose destructor is 0xccfd00): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013cbb40 tears them
 * down (the counted reference at +0x80), the others where its creator
 * FUN_00e90cb0 sets them. 0xe0 bytes (`mov edi, 0xe0` before operator new). */
class Object016d31d8 : public Object00ccfd00 /* derived name */
{
  public:
    /* inlined in the creator FUN_00e90cb0 after the base's constructor
     * (FUN_00ccfbe0, with 4): the vptr, the eight floats at +0x60 from one
     * constant, the reference, the int and the three floats from +0xd0;
     * then the body: the value at +0x90 and the floats from +0xa0 (the
     * three at +0xd0 stored before the value's aligned store, so they are
     * the member list's) */
    Object016d31d8(const Name &name)
        : Object00ccfd00(name, 4), unknown60(0.0f), unknown64(0.0f), unknown68(0.0f),
          unknown6c(1.0f), unknown70(0.0f), unknown74(0.0f), unknown78(0.0f), unknown7c(1.0f),
          unknown88(0), unknown90(1.0f, 0.0f, 0.0f, 0.0f), unknownd0(-90.0f), unknownd4(90.0f),
          unknownd8(0.0f)
    {
        unknowna0 = 1.0f;
        unknowna4 = 0.0f;
        unknowna8 = 0.0f;
        unknownac = 0.0f;
        unknownb0 = 0.0f;
        unknownb4 = 1.0f;
        unknownb8 = 0.0f;
        unknownbc = 0.0f;
        unknownc0 = 0.0f;
        unknownc4 = 1.0f;
        unknownc8 = 0.0f;
        unknowncc = 0.0f;
    }

    virtual ~Object016d31d8();

  private:
    u8 unknown8[0x58];
    float unknown60; /* +0x60: zero from the constructor; not traced */
    float unknown64; /* +0x64: zero from the constructor; not traced */
    float unknown68; /* +0x68: zero from the constructor; not traced */
    float unknown6c; /* +0x6c: 1.0 from the constructor; not traced */
    float unknown70; /* +0x70: zero from the constructor; not traced */
    float unknown74; /* +0x74: zero from the constructor; not traced */
    float unknown78; /* +0x78: zero from the constructor; not traced */
    float unknown7c; /* +0x7c: 1.0 from the constructor; not traced */
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held80;
    int unknown88; /* +0x88: zero from the constructor; not traced */
    u8 unknown8c[0x4];
    /* +0x90: (1.0, 0, 0, 0) from the constructor, one aligned store
     * (`vmovaps [rbx+0x90]`); not traced */
    Float4A unknown90;
    float unknowna0; /* +0xa0: 1.0 from the constructor; not traced */
    float unknowna4; /* +0xa4: zero from the constructor; not traced */
    float unknowna8; /* +0xa8: zero from the constructor; not traced */
    float unknownac; /* +0xac: zero from the constructor; not traced */
    float unknownb0; /* +0xb0: zero from the constructor; not traced */
    float unknownb4; /* +0xb4: 1.0 from the constructor; not traced */
    float unknownb8; /* +0xb8: zero from the constructor; not traced */
    float unknownbc; /* +0xbc: zero from the constructor; not traced */
    float unknownc0; /* +0xc0: zero from the constructor; not traced */
    float unknownc4; /* +0xc4: 1.0 from the constructor; not traced */
    float unknownc8; /* +0xc8: zero from the constructor; not traced */
    float unknowncc; /* +0xcc: zero from the constructor; not traced */
    float unknownd0; /* +0xd0: -90.0 from the constructor; not traced */
    float unknownd4; /* +0xd4: 90.0 from the constructor; not traced */
    float unknownd8; /* +0xd8: zero from the constructor; not traced */
    u8 unknowndc[0x4];
};

#endif
