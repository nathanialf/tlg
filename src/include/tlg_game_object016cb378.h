/* src/include/tlg_game_object016cb378.h: the class whose vtable is at
 * 0x16cb378 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB378_H
#define TLG_GAME_OBJECT016CB378_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb378
 * (config/vtables.derived.base.txt, stored by FUN_0061cee0 FUN_0135fc40 FUN_0135fd80), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced where its destructor FUN_0135fc40 tears them down
 * (the array of Names at +0x118) and where the creator FUN_0061cee0 inlines
 * its constructor (two ints, fifty-five floats and an int set in order: the
 * vectoriser's 16-store chunks give the base's vector stores); their meaning
 * is not traced. 0x138 bytes (the creator's `mov edi, 0x138`). */
class Object016cb378 : public Object016b9108 /* derived name */
{
  public:
    Object016cb378(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown2c(89.0f), unknown30(-89.0f),
          unknown34(5.0f), unknown38(0.2f), unknown3c(0.2f), unknown40(45.0f), unknown44(90.0f),
          unknown48(0.25f), unknown4c(0.5f), unknown50(0.5f), unknown54(0.0f), unknown58(90.0f),
          unknown5c(2.0f), unknown60(-1.0f), unknown64(1.0f), unknown68(45.0f), unknown6c(0.6f),
          unknown70(1.5f), unknown74(20.0f), unknown78(10.0f), unknown7c(8), unknown80(1.0f),
          unknown84(4.0f), unknown88(90.0f), unknown8c(10.0f), unknown90(30.0f), unknown94(1.0f),
          unknown98(5.0f), unknown9c(20.0f), unknowna0(20.0f), unknowna4(5.0f), unknowna8(0.5f),
          unknownac(0.2f), unknownb0(1.0f), unknownb4(0.05f), unknownb8(0.5f), unknownbc(5.0f),
          unknownc0(0.1f), unknownc4(0.1f), unknownc8(0.0f), unknowncc(0.2f), unknownd0(0.1f),
          unknownd4(0.5f), unknownd8(2.0f), unknowndc(0.6f), unknowne0(1.0f), unknowne4(0.01f),
          unknowne8(0.2f), unknownec(0.0f), unknownf0(0.5f), unknownf4(2.0f), unknownf8(45.0f),
          unknownfc(0.5f), unknown100(0.5f), unknown104(1.0f), unknown108(0.75f), unknown10c(2.0f),
          unknown110(1.0f), unknown114(2.0f), unknown130(8.0f)
    {
    }

    virtual ~Object016cb378();

  private:
    int unknown24;    /* +0x24: zero from the constructor; not traced */
    int unknown28;    /* +0x28: zero from the constructor; not traced */
    float unknown2c;  /* +0x2c: 89.0 from the constructor; not traced */
    float unknown30;  /* +0x30: -89.0 from the constructor; not traced */
    float unknown34;  /* +0x34: 5.0 from the constructor; not traced */
    float unknown38;  /* +0x38: 0.2 from the constructor; not traced */
    float unknown3c;  /* +0x3c: 0.2 from the constructor; not traced */
    float unknown40;  /* +0x40: 45.0 from the constructor; not traced */
    float unknown44;  /* +0x44: 90.0 from the constructor; not traced */
    float unknown48;  /* +0x48: 0.25 from the constructor; not traced */
    float unknown4c;  /* +0x4c: 0.5 from the constructor; not traced */
    float unknown50;  /* +0x50: 0.5 from the constructor; not traced */
    float unknown54;  /* +0x54: 0.0 from the constructor; not traced */
    float unknown58;  /* +0x58: 90.0 from the constructor; not traced */
    float unknown5c;  /* +0x5c: 2.0 from the constructor; not traced */
    float unknown60;  /* +0x60: -1.0 from the constructor; not traced */
    float unknown64;  /* +0x64: 1.0 from the constructor; not traced */
    float unknown68;  /* +0x68: 45.0 from the constructor; not traced */
    float unknown6c;  /* +0x6c: 0.6 from the constructor; not traced */
    float unknown70;  /* +0x70: 1.5 from the constructor; not traced */
    float unknown74;  /* +0x74: 20.0 from the constructor; not traced */
    float unknown78;  /* +0x78: 10.0 from the constructor; not traced */
    int unknown7c;    /* +0x7c: 8 from the constructor; not traced */
    float unknown80;  /* +0x80: 1.0 from the constructor; not traced */
    float unknown84;  /* +0x84: 4.0 from the constructor; not traced */
    float unknown88;  /* +0x88: 90.0 from the constructor; not traced */
    float unknown8c;  /* +0x8c: 10.0 from the constructor; not traced */
    float unknown90;  /* +0x90: 30.0 from the constructor; not traced */
    float unknown94;  /* +0x94: 1.0 from the constructor; not traced */
    float unknown98;  /* +0x98: 5.0 from the constructor; not traced */
    float unknown9c;  /* +0x9c: 20.0 from the constructor; not traced */
    float unknowna0;  /* +0xa0: 20.0 from the constructor; not traced */
    float unknowna4;  /* +0xa4: 5.0 from the constructor; not traced */
    float unknowna8;  /* +0xa8: 0.5 from the constructor; not traced */
    float unknownac;  /* +0xac: 0.2 from the constructor; not traced */
    float unknownb0;  /* +0xb0: 1.0 from the constructor; not traced */
    float unknownb4;  /* +0xb4: 0.05 from the constructor; not traced */
    float unknownb8;  /* +0xb8: 0.5 from the constructor; not traced */
    float unknownbc;  /* +0xbc: 5.0 from the constructor; not traced */
    float unknownc0;  /* +0xc0: 0.1 from the constructor; not traced */
    float unknownc4;  /* +0xc4: 0.1 from the constructor; not traced */
    float unknownc8;  /* +0xc8: 0.0 from the constructor; not traced */
    float unknowncc;  /* +0xcc: 0.2 from the constructor; not traced */
    float unknownd0;  /* +0xd0: 0.1 from the constructor; not traced */
    float unknownd4;  /* +0xd4: 0.5 from the constructor; not traced */
    float unknownd8;  /* +0xd8: 2.0 from the constructor; not traced */
    float unknowndc;  /* +0xdc: 0.6 from the constructor; not traced */
    float unknowne0;  /* +0xe0: 1.0 from the constructor; not traced */
    float unknowne4;  /* +0xe4: 0.01 from the constructor; not traced */
    float unknowne8;  /* +0xe8: 0.2 from the constructor; not traced */
    float unknownec;  /* +0xec: 0.0 from the constructor; not traced */
    float unknownf0;  /* +0xf0: 0.5 from the constructor; not traced */
    float unknownf4;  /* +0xf4: 2.0 from the constructor; not traced */
    float unknownf8;  /* +0xf8: 45.0 from the constructor; not traced */
    float unknownfc;  /* +0xfc: 0.5 from the constructor; not traced */
    float unknown100; /* +0x100: 0.5 from the constructor; not traced */
    float unknown104; /* +0x104: 1.0 from the constructor; not traced */
    float unknown108; /* +0x108: 0.75 from the constructor; not traced */
    float unknown10c; /* +0x10c: 2.0 from the constructor; not traced */
    float unknown110; /* +0x110: 1.0 from the constructor; not traced */
    float unknown114; /* +0x114: 2.0 from the constructor; not traced */
    /* +0x118: an array of Names (the block at +0x118, the count at +0x120), its lock at +0x12c: the destructor releases each
     * (`mov r12, [r14+0x118]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> names118;
    float unknown130; /* +0x130: 8.0 from the constructor; not traced */
    u8 unknown134[0x4];
};

#endif
