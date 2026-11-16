/* src/include/tlg_game_object016d3210.h: the class whose vtable is at
 * 0x16d3210 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D3210_H
#define TLG_GAME_OBJECT016D3210_H

#include "tlg_game_object016d31d8.h"

/* derived names: the class whose vtable is at 0x16d3210
 * (config/vtables.derived.base.txt, stored by FUN_00e91f20 FUN_013cbca0 FUN_013cbd50), derived from
 * Object00ccfd00 (the class whose destructor is 0xccfd00): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013cbca0 tears them
 * down (the counted reference at +0x80), the others where its creator
 * FUN_00e91f20 sets them. 0xe0 bytes (`mov edi, 0xe0` before operator new). */
class Object016d3210 : public Object00ccfd00, public Base016d31d8 /* derived name */
{
  public:
    /* inlined in the creator FUN_00e91f20 after the base's constructor
     * (FUN_00ccfbe0, with 5) and the second base's: the vptr, the
     * reference, the int and the three floats from +0xd0; then the body: the
     * x axis at +0x90, the floats from +0xa0, the x axis at +0xb4, the floats
     * after it (each assigned from the constant lane by lane: the copies are
     * integer moves until the link folds them) */
    Object016d3210(const Name &name)
        : Object00ccfd00(name, 5), unknown88(0), unknownd0(-1e9f), unknownd4(1e9f), unknownd8(0.0f)
    {
        unknown90 = FLOAT4_X;
        unknowna0 = 1.0f;
        unknowna4 = 0.0f;
        unknowna8 = 0.0f;
        unknownac = 0.0f;
        unknownb0 = 0.0f;
        unknownb4 = FLOAT4_X;
        unknownc4 = 1.0f;
        unknownc8 = 0.0f;
        unknowncc = 0.0f;
    }

    virtual ~Object016d3210();

  private:
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held80;
    int unknown88; /* +0x88: zero from the constructor; not traced */
    u8 unknown8c[0x4];
    /* +0x90: the x axis from the constructor, one aligned store
     * (`vmovaps [rbx+0x90]`); not traced */
    Float4A unknown90;
    float unknowna0;  /* +0xa0: 1.0 from the constructor; not traced */
    float unknowna4;  /* +0xa4: zero from the constructor; not traced */
    float unknowna8;  /* +0xa8: zero from the constructor; not traced */
    float unknownac;  /* +0xac: zero from the constructor; not traced */
    float unknownb0;  /* +0xb0: zero from the constructor; not traced */
    Float4 unknownb4; /* +0xb4: the x axis from the constructor; not traced */
    float unknownc4;  /* +0xc4: 1.0 from the constructor; not traced */
    float unknownc8;  /* +0xc8: zero from the constructor; not traced */
    float unknowncc;  /* +0xcc: zero from the constructor; not traced */
    float unknownd0;  /* +0xd0: -1e9 from the constructor; not traced */
    float unknownd4;  /* +0xd4: 1e9 from the constructor; not traced */
    float unknownd8;  /* +0xd8: zero from the constructor; not traced */
    u8 unknowndc[0x4];
};

#endif
