/* src/include/tlg_game_object00cf7fb0.h: the class whose destructor is
 * 0xcf7fb0, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT00CF7FB0_H
#define TLG_GAME_OBJECT00CF7FB0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose complete destructor is 0xcf7fb0 (its row
 * named for it, D15). The classes derived from it tail-call that destructor
 * from their own (the files that include this header). The destructor is
 * not written, so nothing here emits the vtable; the class's other slots
 * and its fields are not traced. */
class Object00cf7fb0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creators FUN_00cf9470 (kind 7) and FUN_00cfc3e0 (kind
     * 6) before the derived class's vptr: the ints at +0x28 (one 16-byte
     * store), two copies of the origin from +0x40 (one 32-byte integer
     * store), three floats, the point (0, 0, 0, 1) at +0x70, the int, the
     * kind and the four ints at +0xb8; then the body: a point at +0x90
     * (-0.0 three times, FLOAT_ONE's copy) and the origin at +0xa0 (with the
     * w before it, one 16-byte integer store at +0x9c: the unit's vectoriser
     * meets them in two of its 16-store chunks, the link's in one) */
    Object00cf7fb0(const Name &name, int kind)
        : Object016b9108(name), unknown28(0), unknown2c(0), unknown30(0), unknown34(0),
          unknown40(FLOAT4_POINT_ORIGIN), unknown50(FLOAT4_POINT_ORIGIN), unknown60(1.0f),
          unknown64(1.0f), unknown68(1.5f), unknown70(0.0f, 0.0f, 0.0f, 1.0f), unknown80(0),
          kindb0(kind), unknownb8(0), unknownbc(0), unknownc0(0), unknownc4(0)
    {
        unknown90 = -0.0f;
        unknown94 = -0.0f;
        unknown98 = -0.0f;
        unknown9c = FLOAT_ONE;
        unknowna0 = Float4(FLOAT4_POINT_ORIGIN);
    }

    virtual ~Object00cf7fb0();

  private:
    u8 unknown24[0x4];
    int unknown28; /* +0x28: zero from the constructor; not traced */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown34; /* +0x34: zero from the constructor; not traced */
    u8 unknown38[0x8];
    Float4 unknown40; /* +0x40: the origin from the constructor; not traced */
    Float4 unknown50; /* +0x50: the origin from the constructor; not traced */
    float unknown60;  /* +0x60: 1.0 from the constructor; not traced */
    float unknown64;  /* +0x64: 1.0 from the constructor; not traced */
    float unknown68;  /* +0x68: 1.5 from the constructor; not traced */
    u8 unknown6c[0x4];
    Float4 unknown70; /* +0x70: (0, 0, 0, 1) from the constructor; not traced */
    int unknown80;    /* +0x80: zero from the constructor; not traced */
    u8 unknown84[0xc];
    float unknown90;  /* +0x90: -0.0 from the constructor; not traced */
    float unknown94;  /* +0x94: -0.0 from the constructor; not traced */
    float unknown98;  /* +0x98: -0.0 from the constructor; not traced */
    float unknown9c;  /* +0x9c: FLOAT_ONE from the constructor; not traced */
    Float4 unknowna0; /* +0xa0: the origin from the constructor; not traced */
    int kindb0;       /* +0xb0: the constructor's argument (7, 6); derived name */
    u8 unknownb4[0x4];
    int unknownb8; /* +0xb8: zero from the constructor; not traced */
    int unknownbc; /* +0xbc: zero from the constructor; not traced */
    int unknownc0; /* +0xc0: zero from the constructor; not traced */
    int unknownc4; /* +0xc4: zero from the constructor; not traced */
};

#endif
