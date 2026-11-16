/* src/include/tlg_game_object016a93c0.h: the class whose vtable is at
 * 0x16a93c0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A93C0_H
#define TLG_GAME_OBJECT016A93C0_H

#include <float.h>

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a93c0
 * (config/vtables.derived.base.txt, stored by FUN_003ed1e0 FUN_003ed400), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields from +0x24
 * are traced where its creator FUN_003ed1e0 sets them and its destructor
 * FUN_003ed400 tears them down (the array of Names at +0x38, the Names at
 * +0x64, +0x60, +0x28, +0x24). 0xe0 bytes (`mov edi, 0xe0` before operator
 * new). */
class Object016a93c0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_003ed1e0: the base built from the name, the
     * vptr, the names and the array empty, the eight floats from +0x98 (one
     * 32-byte store); then the body in the base's order (the x axis copied
     * at +0x7c: integer moves until the link folds them, `vmovd`) */
    Object016a93c0(const Name &name)
        : Object016b9108(name), unknown98(0.3f), unknown9c(2.0f), unknowna0(0.0f),
          unknowna4(FLT_MAX), unknowna8(0.3f), unknownac(2.0f), unknownb0(0.0f), unknownb4(FLT_MAX)
    {
        unknown2c = 0;
        unknown30 = 0;
        unknown50.set(0.0f, 0.0f, 0.0f, 1.0f);
        unknown68 = 0.0f;
        unknown6c = 0.0f;
        unknown70 = 0.0f;
        unknown74 = 0.0f;
        unknown78 = 0.0f;
        unknown7c = Float4(FLOAT4_X);
        unknown8c = 1.0f;
        unknown90 = 0;
        unknown94 = 0;
        unknownb8 = 0;
        unknownc0.set(0.0f, 0.0f, 0.0f, 1.0f);
        unknownd0 = 0.0f;
        unknownd4 = 0.0f;
        unknownd8 = 0.0f;
        unknowndc = 0.0f;
    }

    virtual ~Object016a93c0();

  private:
    Name name24;   /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name name28;   /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    u8 unknown34[0x4];
    /* +0x38: an array of Names with its lock (the word at +0x4c): the
     * destructor releases each (`mov r12, [r14+0x38]; mov ecx, [r12+rbx*4]`
     * ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> names38;
    Float4A unknown50; /* +0x50: (0, 0, 0, 1) from the constructor; not traced */
    Name name60;       /* +0x60: released by the destructor (`mov eax, [rbx+0x60]; shl 5`) */
    Name name64;       /* +0x64: released by the destructor (`mov eax, [rbx+0x64]; shl 5`) */
    float unknown68;   /* +0x68: zero from the constructor; not traced */
    float unknown6c;   /* +0x6c: zero from the constructor; not traced */
    float unknown70;   /* +0x70: zero from the constructor; not traced */
    float unknown74;   /* +0x74: zero from the constructor; not traced */
    float unknown78;   /* +0x78: zero from the constructor; not traced */
    Float4 unknown7c;  /* +0x7c: the x axis from the constructor; not traced */
    float unknown8c;   /* +0x8c: 1.0 from the constructor; not traced */
    int unknown90;     /* +0x90: zero from the constructor; not traced */
    int unknown94;     /* +0x94: zero from the constructor; not traced */
    float unknown98;   /* +0x98: 0.3 from the constructor; not traced */
    float unknown9c;   /* +0x9c: 2.0 from the constructor; not traced */
    float unknowna0;   /* +0xa0: zero from the constructor; not traced */
    float unknowna4;   /* +0xa4: FLT_MAX from the constructor; not traced */
    float unknowna8;   /* +0xa8: 0.3 from the constructor; not traced */
    float unknownac;   /* +0xac: 2.0 from the constructor; not traced */
    float unknownb0;   /* +0xb0: zero from the constructor; not traced */
    float unknownb4;   /* +0xb4: FLT_MAX from the constructor; not traced */
    int unknownb8;     /* +0xb8: zero from the constructor; not traced */
    Float4A unknownc0; /* +0xc0: (0, 0, 0, 1) from the constructor; not traced */
    float unknownd0;   /* +0xd0: zero from the constructor; not traced */
    float unknownd4;   /* +0xd4: zero from the constructor; not traced */
    float unknownd8;   /* +0xd8: zero from the constructor; not traced */
    float unknowndc;   /* +0xdc: zero from the constructor; not traced */
};

#endif
