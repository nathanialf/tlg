/* src/include/tlg_game_object016cb3b0.h: the class whose vtable is at
 * 0x16cb3b0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB3B0_H
#define TLG_GAME_OBJECT016CB3B0_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived name: the point Object016cb3b0's constructor copies to +0x40
 * (`mov rax, [0x580f920]` and `[0x580f928]`, stored as four words) */
extern Float4 D_580f920;

/* derived names: the class whose vtable is at 0x16cb3b0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00623110,
 * leaf_00623110.cpp, and its destructor FUN_0135fed0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x150 bytes: from the constructor: empty Names at +0x28, +0x30
 * and +0x34 among zeros from +0x24, a copy of the point at 0x580f920 at
 * +0x40, the points (1, 1, 1, 0) at +0x54 and (0, 5, 1, 1) at +0x68, the
 * bounds -90 and 90 at +0x7c, five records of a count (3, 3, 1, 3, 3) and
 * zeros from +0x84, the bounds again at +0x104, a locked array of Names
 * at +0x110, (30, 90, 0.1, 0.5) at +0x128, 0.25 at +0x138, an empty Name
 * at +0x13c and zeros after it; the other fields are not traced. The
 * destructor is implicit: the complete one, FUN_0135fec0, is a jump to
 * the base-object one, FUN_0135fed0 (the Name at +0x13c, the array of
 * Names and the Names at +0x34, +0x30 and +0x28, then the root's
 * destructor in line), and the deleting one, FUN_013600f0, calls it: its
 * cost is over the inline limit of 325 (the inline hint). The class has
 * no key function, so the creator's unit emits the vtable with them. */
class Object016cb3b0 : public Object016b9108 /* derived name */
{
  public:
    Object016cb3b0(const Name &name)
        : Object016b9108(name), unknown24(0), unknown2c(0), unknown38(0), unknown40(D_580f920),
          unknown50(0), unknown54(1.0f, 1.0f, 1.0f, 0.0f), unknown64(0),
          unknown68(0.0f, 5.0f, 1.0f, 1.0f), unknown78(0), minimum7c(-90.0f), maximum80(90.0f),
          count84(3), unknown88(), unknown98(0), count9c(3), unknowna0(), unknownb0(0), countb4(1),
          unknownb8(), countd4(3), unknownd8(), unknowne8(0), countec(3), unknownf0(),
          unknown100(0), minimum104(-90.0f), maximum108(90.0f),
          unknown128(30.0f, 90.0f, 0.1f, 0.5f), unknown138(0.25f), unknown140(0), unknown144(0)
    {
    }

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    Name name28;   /* +0x28 */
    int unknown2c; /* +0x2c: 0 from the constructor */
    Name name30;   /* +0x30 */
    Name name34;   /* +0x34 */
    int unknown38; /* +0x38: 0 from the constructor */
    u8 unknown3c[0x4];
    Float4 unknown40; /* +0x40: a copy of D_580f920 */
    int unknown50;    /* +0x50: 0 from the constructor */
    Float4 unknown54; /* +0x54: (1, 1, 1, 0) from the constructor */
    int unknown64;    /* +0x64: 0 from the constructor */
    Float4 unknown68; /* +0x68: (0, 5, 1, 1) from the constructor */
    int unknown78;    /* +0x78: 0 from the constructor */
    float minimum7c;  /* +0x7c: -90 from the constructor */
    float maximum80;  /* +0x80: 90 from the constructor */
    int count84;      /* +0x84: 3 from the constructor */
    int unknown88[4]; /* +0x88: zeros from the constructor; not traced */
    int unknown98;    /* +0x98: 0 from the constructor */
    int count9c;      /* +0x9c: 3 from the constructor */
    int unknowna0[4]; /* +0xa0: zeros from the constructor; not traced */
    int unknownb0;    /* +0xb0: 0 from the constructor */
    int countb4;      /* +0xb4: 1 from the constructor */
    int unknownb8[7]; /* +0xb8: zeros from the constructor; not traced */
    int countd4;      /* +0xd4: 3 from the constructor */
    int unknownd8[4]; /* +0xd8: zeros from the constructor; not traced */
    int unknowne8;    /* +0xe8: 0 from the constructor */
    int countec;      /* +0xec: 3 from the constructor */
    int unknownf0[4]; /* +0xf0: zeros from the constructor; not traced */
    int unknown100;   /* +0x100: 0 from the constructor */
    float minimum104; /* +0x104: -90 from the constructor */
    float maximum108; /* +0x108: 90 from the constructor */
    u8 unknown10c[0x4];
    Array01343a80<Name> names110; /* +0x110 */
    Float4 unknown128;            /* +0x128: (30, 90, 0.1, 0.5) from the constructor */
    float unknown138;             /* +0x138: 0.25 from the constructor */
    Name name13c;                 /* +0x13c */
    int unknown140;               /* +0x140: 0 from the constructor */
    int unknown144;               /* +0x144: 0 from the constructor */
    u8 unknown148[0x8];
};

#endif
