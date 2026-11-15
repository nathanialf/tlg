/* src/include/tlg_game_object016d21d8.h: the class whose vtable is at
 * 0x16d21d8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D21D8_H
#define TLG_GAME_OBJECT016D21D8_H

#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d21d8
 * (config/vtables.derived.base.txt, stored by FUN_00d10e60 FUN_013b5680), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields from +0x24
 * are traced where its creator FUN_00d10e60 sets them and its destructor FUN_013b5680
 * tears them down. 0xb0 bytes (`mov edi, 0xb0` before operator new). The
 * same fields from +0x30 as Object016ab9a0. */
class Object016d21d8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_00d10e60: the vptr, the fields in their order (the
     * zeros at +0x30 one 16-byte integer store, the four floats at +0x40 and
     * the eight at +0x90 one store each; the copies of FLOAT4_ONE and
     * FLOAT_ONE integer stores, so the floats around them stay apart) */
    Object016d21d8(const Name &name)
        : Object016b9108(name), unknown24(0), unknown30(0), unknown34(0), unknown38(0),
          unknown3c(0), unknown40(1.0f), unknown44(1.0f), unknown48(0.99f), unknown4c(200.0f),
          unknown50(100.0f), unknown60(-1.0f), unknown64(-1.0f), unknown68(-1.0f),
          unknown6c(FLOAT4_ONE), unknown7c(FLOAT_ONE), unknown80(0.2f), unknown84(0.3f),
          unknown88(1.0f), unknown90(0.0f, 0.0f, 0.0f, 1.0f), unknowna0(0.0f, 0.0f, 0.0f, 1.0f)
    {
    }

    virtual ~Object016d21d8();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    Name name28;   /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    u8 unknown2c[0x4];
    int unknown30;   /* +0x30: zero from the constructor; not traced */
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    int unknown38;   /* +0x38: zero from the constructor; not traced */
    int unknown3c;   /* +0x3c: zero from the constructor; not traced */
    float unknown40; /* +0x40: 1.0 from the constructor; not traced */
    float unknown44; /* +0x44: 1.0 from the constructor; not traced */
    float unknown48; /* +0x48: 0.99 from the constructor; not traced */
    float unknown4c; /* +0x4c: 200.0 from the constructor; not traced */
    float unknown50; /* +0x50: 100.0 from the constructor; not traced */
    u8 unknown54[0xc];
    float unknown60;   /* +0x60: -1.0 from the constructor; not traced */
    float unknown64;   /* +0x64: -1.0 from the constructor; not traced */
    float unknown68;   /* +0x68: -1.0 from the constructor; not traced */
    Float4 unknown6c;  /* +0x6c: FLOAT4_ONE from the constructor; not traced */
    float unknown7c;   /* +0x7c: FLOAT_ONE from the constructor; not traced */
    float unknown80;   /* +0x80: 0.2 from the constructor; not traced */
    float unknown84;   /* +0x84: 0.3 from the constructor; not traced */
    float unknown88;   /* +0x88: 1.0 from the constructor; not traced */
    Float4A unknown90; /* +0x90: (0, 0, 0, 1) from the constructor; not traced */
    Float4A unknowna0; /* +0xa0: (0, 0, 0, 1) from the constructor; not traced */
};

#endif
