/* src/include/tlg_game_base016cbbf8.h: plain bases of game classes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_BASE016CBBF8_H
#define TLG_GAME_BASE016CBBF8_H

#include <float.h>

#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: a base with no virtual function, the second base of
 * Object016cbbf8 and Object016cbc30 (at +0x24, in the first base's tail):
 * their creators FUN_007adaa0 and FUN_007adc20 store these fields BEFORE the
 * class's vptr (the vptr is stored once every base is built): two ints and
 * four ones (one 16-byte store). 0x1c bytes. */
struct Base016cbbf8 /* derived name */
{
    Base016cbbf8() : unknown0(0), unknown4(0), unknownc(1.0f, 1.0f, 1.0f, 1.0f) {}

    int unknown0; /* +0x0: zero from the constructor; not traced */
    int unknown4; /* +0x4: zero from the constructor; not traced */
    u8 unknown8[0x4];
    Float4 unknownc; /* +0xc: ones from the constructor; not traced */
};

/* derived names: a base with no virtual function, the second base of
 * Object016d2450 and Object016d2488 (at +0x24), stored before the vptr by
 * their creators FUN_00d63920 and FUN_00d63aa0: 0.6 and 0.4, then two points
 * (0, 0, 0, 1) (one 32-byte store). 0x2c bytes. */
struct Base016d2450 /* derived name */
{
    Base016d2450()
        : unknown0(0.6f), unknown4(0.4f), unknownc(0.0f, 0.0f, 0.0f, 1.0f),
          unknown1c(0.0f, 0.0f, 0.0f, 1.0f)
    {
    }

    float unknown0; /* +0x0: 0.6 from the constructor; not traced */
    float unknown4; /* +0x4: 0.4 from the constructor; not traced */
    u8 unknown8[0x4];
    Float4 unknownc;  /* +0xc: (0, 0, 0, 1) from the constructor; not traced */
    Float4 unknown1c; /* +0x1c: (0, 0, 0, 1) from the constructor; not traced */
};

/* derived names: a base with no virtual function, the second base (at +0x24)
 * of Object016cb958 and Object016cb990, stored before the vptr by their
 * creators FUN_007a2150 and FUN_007a2300: 3.0 and 100.0, three -1.0 and a
 * copy of FLOAT_ONE (an integer store, so the four stay apart), 0.6 and 0.4,
 * two points (0, 0, 0, 1) (one 32-byte store) and an int. 0x50 bytes. */
struct Base016cb958 /* derived name */
{
    Base016cb958()
        : unknown0(3.0f), unknown4(100.0f), unknownc(-1.0f), unknown10(-1.0f), unknown14(-1.0f),
          unknown18(FLOAT_ONE), unknown1c(0.6f), unknown20(0.4f), unknown2c(0.0f, 0.0f, 0.0f, 1.0f),
          unknown3c(0.0f, 0.0f, 0.0f, 1.0f), unknown4c(0)
    {
    }

    float unknown0; /* +0x0: 3.0 from the constructor; not traced */
    float unknown4; /* +0x4: 100.0 from the constructor; not traced */
    u8 unknown8[0x4];
    float unknownc;  /* +0xc: -1.0 from the constructor; not traced */
    float unknown10; /* +0x10: -1.0 from the constructor; not traced */
    float unknown14; /* +0x14: -1.0 from the constructor; not traced */
    float unknown18; /* +0x18: FLOAT_ONE from the constructor; not traced */
    float unknown1c; /* +0x1c: 0.6 from the constructor; not traced */
    float unknown20; /* +0x20: 0.4 from the constructor; not traced */
    u8 unknown24[0x8];
    Float4 unknown2c; /* +0x2c: (0, 0, 0, 1) from the constructor; not traced */
    Float4 unknown3c; /* +0x3c: (0, 0, 0, 1) from the constructor; not traced */
    int unknown4c;    /* +0x4c: zero from the constructor; not traced */
};

/* derived names: a base with no virtual function, the second base (at +0x24)
 * of Object016cba70, stored before the vptr by its creator FUN_007a2a80:
 * ones, zeros, the origin, the lowest and the highest point (floats: the
 * zeros from +0x40 one memset, the floats from +0x5c one 32-byte store), a
 * copy of FLOAT4_ONE (an integer vector of its own), -1.0, 1.0 and an int.
 * 0x78 bytes. */
struct Base016cba70 /* derived name */
{
    Base016cba70()
        : unknownc(1.0f, 1.0f, 1.0f, 1.0f), unknown1c(0.0f, 0.0f, 0.0f, 0.0f),
          unknown2c(0.0f, 0.0f, 0.0f, 1.0f), unknown3c(-FLT_MAX, -FLT_MAX, -FLT_MAX, 1.0f),
          unknown4c(FLT_MAX, FLT_MAX, FLT_MAX, 1.0f), unknown5c(FLOAT4_ONE), unknown6c(-1.0f),
          unknown70(1.0f), unknown74(0)
    {
    }

    u8 unknown0[0xc];
    Float4 unknownc;  /* +0xc: ones from the constructor; not traced */
    Float4 unknown1c; /* +0x1c: zeros from the constructor; not traced */
    Float4 unknown2c; /* +0x2c: the origin from the constructor; not traced */
    Float4 unknown3c; /* +0x3c: the lowest point from the constructor; not traced */
    Float4 unknown4c; /* +0x4c: the highest point from the constructor; not traced */
    Float4 unknown5c; /* +0x5c: FLOAT4_ONE from the constructor; not traced */
    float unknown6c;  /* +0x6c: -1.0 from the constructor; not traced */
    float unknown70;  /* +0x70: 1.0 from the constructor; not traced */
    int unknown74;    /* +0x74: zero from the constructor; not traced */
};

#endif
