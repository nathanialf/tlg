/* src/include/tlg_game_object016ce340.h: the class whose vtable is at
 * 0x16ce340 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE340_H
#define TLG_GAME_OBJECT016CE340_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ce340
 * (config/vtables.derived.base.txt, stored by FUN_00a54070 FUN_0138cd60
 * FUN_0138ce30), derived from Object016b9108. 0xa0 bytes (`mov edi,
 * 0xa0` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a54070 sets them and its destructor FUN_0138cd60
 * tears them down. The destructor is the class's key function
 * (leaf_0138cd60.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016ce340 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the fields from +0x24
     * in their order: separate `mov dword` stores where the types alternate,
     * the four floats at +0x38 from the constant at 0x153cd20 (0, 10, 5, 2) and
     * the eight at +0x68 from the one at 0x14e54e0 in one store each (the
     * vectoriser: four or eight consecutive fields of one type), the name at
     * +0x94 and the int after it in one `mov qword` (the last two stores of one type) */
    Object016ce340(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown2c(200), unknown30(0.0f),
          unknown34(4), unknown38(0.0f), unknown3c(10.0f), unknown40(5.0f), unknown44(2.0f),
          unknown48(5.0f), unknown4c(2.0f), unknown50(100), unknown54(200), unknown58(500),
          unknown5c(1200.0f), unknown60(150.0f), unknown64(10), unknown68(0.4f), unknown6c(0.7f),
          unknown70(0.5f), unknown74(0.5f), unknown78(2.0f), unknown7c(1.0f), unknown80(30.0f),
          unknown84(30.0f), unknown88(1.0f), unknown8c(1.0f), unknown90(0.0f), unknown98(0)
    {
    }

    virtual ~Object016ce340();

  private:
    int unknown24;   /* +0x24: zero from the constructor; not traced */
    int unknown28;   /* +0x28: zero from the constructor; not traced */
    int unknown2c;   /* +0x2c: 200 from the constructor; not traced */
    float unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown34;   /* +0x34: 4 from the constructor; not traced */
    float unknown38; /* +0x38: zero from the constructor; not traced */
    float unknown3c; /* +0x3c: 10.0 from the constructor; not traced */
    float unknown40; /* +0x40: 5.0 from the constructor; not traced */
    float unknown44; /* +0x44: 2.0 from the constructor; not traced */
    float unknown48; /* +0x48: 5.0 from the constructor; not traced */
    float unknown4c; /* +0x4c: 2.0 from the constructor; not traced */
    int unknown50;   /* +0x50: 100 from the constructor; not traced */
    int unknown54;   /* +0x54: 200 from the constructor; not traced */
    int unknown58;   /* +0x58: 500 from the constructor; not traced */
    float unknown5c; /* +0x5c: 1200.0 from the constructor; not traced */
    float unknown60; /* +0x60: 150.0 from the constructor; not traced */
    int unknown64;   /* +0x64: 10 from the constructor; not traced */
    float unknown68; /* +0x68: 0.4 from the constructor; not traced */
    float unknown6c; /* +0x6c: 0.7 from the constructor; not traced */
    float unknown70; /* +0x70: 0.5 from the constructor; not traced */
    float unknown74; /* +0x74: 0.5 from the constructor; not traced */
    float unknown78; /* +0x78: 2.0 from the constructor; not traced */
    float unknown7c; /* +0x7c: 1.0 from the constructor; not traced */
    float unknown80; /* +0x80: 30.0 from the constructor; not traced */
    float unknown84; /* +0x84: 30.0 from the constructor; not traced */
    float unknown88; /* +0x88: 1.0 from the constructor; not traced */
    float unknown8c; /* +0x8c: 1.0 from the constructor; not traced */
    float unknown90; /* +0x90: zero from the constructor; not traced */
    Name name94;     /* +0x94: empty from the constructor, released by the destructor */
    int unknown98;   /* +0x98: zero from the constructor; not traced */
    u8 unknown9c[0x4];
};

#endif
