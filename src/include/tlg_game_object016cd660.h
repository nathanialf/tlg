/* src/include/tlg_game_object016cd660.h: the class whose vtable is at
 * 0x16cd660 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD660_H
#define TLG_GAME_OBJECT016CD660_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16cd660
 * (config/vtables.derived.base.txt, stored by FUN_009b3b10 FUN_01386900
 * FUN_013869c0), derived from Object016b9108. 0xe0 bytes (`mov edi,
 * 0xe0` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b3b10 sets them and its destructor FUN_01386900
 * tears them down.
 * The destructor is implicit: FUN_01386900 and the deleting
 * FUN_013869c0 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_009b3b10.cpp) emits the vtable
 * with both. */
class Object016cd660 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword` stores from
     * +0x24 (the name, then floats and ints alternating), the four floats at
     * +0x60 and +0x80 from the constants at 0x153b3c0 and 0x153b3d0, then the
     * body's values from +0x98: two of them pairs of floats in one `movabs`
     * (0 and 0.5 at +0x98, 0 and 20.0 at +0xc8: one value of two floats each,
     * assigned whole) */
    Object016cd660(const Name &name)
        : Object016b9108(name), unknown28(0.1f), unknown2c(0), unknown30(0.02f), unknown34(0),
          unknown38(45.0f), unknown3c(0), unknown40(20.0f), unknown44(0), unknown48(0.06f),
          unknown4c(0), unknown50(20.0f), unknown54(0), unknown58(-40.0f), unknown5c(0),
          unknown60(0.05f), unknown64(-0.2f), unknown68(0.0f), unknown6c(0.0f), unknown70(0),
          unknown80(0.05f), unknown84(0.4f), unknown88(0.0f), unknown8c(0.0f), unknown90(0),
          unknown94(0.001f)
    {
        unknown98 = Pair0057e850(0.0f, 0.5f);
        unknowna0 = 0;
        unknowna4 = 0;
        unknowna8 = 0;
        unknownac = 0;
        unknownb0 = 0;
        unknownb4 = 0.3f;
        unknownb8 = 0;
        unknownbc = 10.0f;
        unknownc0 = 0;
        unknownc4 = 20.0f;
        unknownc8 = Pair0057e850(0.0f, 20.0f);
        unknownd0 = 0;
    }

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    float unknown28; /* +0x28: 0.1 from the constructor; not traced */
    int unknown2c;   /* +0x2c: zero from the constructor; not traced */
    float unknown30; /* +0x30: 0.02 from the constructor; not traced */
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 45.0 from the constructor; not traced */
    int unknown3c;   /* +0x3c: zero from the constructor; not traced */
    float unknown40; /* +0x40: 20.0 from the constructor; not traced */
    int unknown44;   /* +0x44: zero from the constructor; not traced */
    float unknown48; /* +0x48: 0.06 from the constructor; not traced */
    int unknown4c;   /* +0x4c: zero from the constructor; not traced */
    float unknown50; /* +0x50: 20.0 from the constructor; not traced */
    int unknown54;   /* +0x54: zero from the constructor; not traced */
    float unknown58; /* +0x58: -40.0 from the constructor; not traced */
    int unknown5c;   /* +0x5c: zero from the constructor; not traced */
    float unknown60; /* +0x60: 0.05 from the constructor; not traced */
    float unknown64; /* +0x64: -0.2 from the constructor; not traced */
    float unknown68; /* +0x68: zero from the constructor; not traced */
    float unknown6c; /* +0x6c: zero from the constructor; not traced */
    int unknown70;   /* +0x70: zero from the constructor; not traced */
    u8 unknown74[0xc];
    float unknown80;        /* +0x80: 0.05 from the constructor; not traced */
    float unknown84;        /* +0x84: 0.4 from the constructor; not traced */
    float unknown88;        /* +0x88: zero from the constructor; not traced */
    float unknown8c;        /* +0x8c: zero from the constructor; not traced */
    int unknown90;          /* +0x90: zero from the constructor; not traced */
    float unknown94;        /* +0x94: 0.001 from the constructor; not traced */
    Pair0057e850 unknown98; /* +0x98: 0 and 0.5 from the constructor; not traced */
    int unknowna0;          /* +0xa0: zero from the constructor; not traced */
    int unknowna4;          /* +0xa4: zero from the constructor; not traced */
    int unknowna8;          /* +0xa8: zero from the constructor; not traced */
    int unknownac;          /* +0xac: zero from the constructor; not traced */
    int unknownb0;          /* +0xb0: zero from the constructor; not traced */
    float unknownb4;        /* +0xb4: 0.3 from the constructor; not traced */
    int unknownb8;          /* +0xb8: zero from the constructor; not traced */
    float unknownbc;        /* +0xbc: 10.0 from the constructor; not traced */
    int unknownc0;          /* +0xc0: zero from the constructor; not traced */
    float unknownc4;        /* +0xc4: 20.0 from the constructor; not traced */
    Pair0057e850 unknownc8; /* +0xc8: 0 and 20.0 from the constructor; not traced */
    int unknownd0;          /* +0xd0: zero from the constructor; not traced */
    u8 unknownd4[0xc];
};

#endif
