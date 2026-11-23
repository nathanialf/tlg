/* src/include/tlg_game_object016d31d8.h: the class whose vtable is at
 * 0x16d31d8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D31D8_H
#define TLG_GAME_OBJECT016D31D8_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_math.h"
#include "tlg_game_object00ccfd00.h"

/* derived names: a base with no virtual function, the second base (at +0x60)
 * of Object016d31d8 and Object016d3210: their creators FUN_00e90cb0 and
 * FUN_00e91f20 store it BEFORE the class's vptr (one 32-byte store of two
 * points (0, 0, 0, 1)). 0x20 bytes, 16-byte aligned: it starts at +0x60,
 * past the base's 0x58 bytes. */
struct Base016d31d8 /* derived name */
{
    Base016d31d8() : unknown0(0.0f, 0.0f, 0.0f, 1.0f), unknown10(0.0f, 0.0f, 0.0f, 1.0f) {}

    Float4A unknown0;  /* +0x0: (0, 0, 0, 1) from the constructor; not traced */
    Float4A unknown10; /* +0x10: (0, 0, 0, 1) from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16d31d8
 * (config/vtables.derived.base.txt, stored by FUN_00e90cb0 FUN_013cbb40 FUN_013cbbf0), derived from
 * Object00ccfd00 (the class whose destructor is 0xccfd00): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013cbb40 tears them
 * down (the counted reference at +0x80), the others where its creator
 * FUN_00e90cb0 sets them. 0xe0 bytes (`mov edi, 0xe0` before operator new).
 * The destructor is implicit: FUN_013cbb40 and the deleting
 * FUN_013cbbf0 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_00e90cb0.cpp) emits the vtable
 * with both. */
class Object016d31d8 : public Object00ccfd00, public Base016d31d8 /* derived name */
{
  public:
    /* inlined in the creator FUN_00e90cb0 after the base's constructor
     * (FUN_00ccfbe0, with 4) and the second base's: the vptr, the
     * reference, the int and the three floats from +0xd0; then the body: the
     * x axis at +0x90, the floats from +0xa0, the x axis at +0xb4, the floats
     * after it (each assigned from the constant lane by lane: the copies are
     * integer moves until the link folds them) */
    Object016d31d8(const Name &name)
        : Object00ccfd00(name, 4), unknown88(0), unknownd0(-90.0f), unknownd4(90.0f),
          unknownd8(0.0f)
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

  private:
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held80;
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
    float unknownd0;  /* +0xd0: -90.0 from the constructor; not traced */
    float unknownd4;  /* +0xd4: 90.0 from the constructor; not traced */
    float unknownd8;  /* +0xd8: zero from the constructor; not traced */
    u8 unknowndc[0x4];
};

#endif
