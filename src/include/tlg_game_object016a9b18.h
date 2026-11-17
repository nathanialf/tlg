/* src/include/tlg_game_object016a9b18.h: the class whose vtable is at 0x16a9b18
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9B18_H
#define TLG_GAME_OBJECT016A9B18_H

#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9b18
 * (config/vtables.derived.base.txt, stored by its creator FUN_004637c0, where
 * its constructor is inlined, and by its complete destructor FUN_00463990,
 * leaf_00463990.cpp), derived from Object016b9108: its slots 2 to 4 are the
 * base's. 0xe0 bytes (`mov edi, 0xe0` before operator new in the creator).
 * Its fields are traced only where the creator sets them. */
class Object016a9b18 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, then
     * the fields in their order: -1.0 five times from +0x2c (one 16-byte
     * constant and one four-byte store), the negative infinity at +0x80 */
    Object016a9b18(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown2c(-1.0f), unknown30(-1.0f),
          unknown34(-1.0f), unknown38(-1.0f), unknown3c(-1.0f), unknown40(0), unknown44(0),
          unknown48(0), unknown4c(0), unknown50(0), unknown54(0), unknown58(0), unknown60(0),
          unknown68(0), unknown70(0.0f, 0.0f, 0.0f, 0.0f), unknown80(-HUGE_VALF),
          unknown90(0.0f, 0.0f, 0.0f, 0.0f), unknowna0(), unknownc0(0.0f, 0.0f, 0.0f, 0.0f),
          unknownd0(0.0f), unknownd4(0)
    {
    }

    virtual ~Object016a9b18();

  private:
    int unknown24;   /* +0x24: 0 from the constructor */
    int unknown28;   /* +0x28: 0 from the constructor */
    float unknown2c; /* +0x2c: -1.0 from the constructor */
    float unknown30; /* +0x30: -1.0 from the constructor */
    float unknown34; /* +0x34: -1.0 from the constructor */
    float unknown38; /* +0x38: -1.0 from the constructor */
    float unknown3c; /* +0x3c: -1.0 from the constructor */
    int unknown40;   /* +0x40: 0 from the constructor */
    int unknown44;   /* +0x44: 0 from the constructor */
    int unknown48;   /* +0x48: 0 from the constructor */
    int unknown4c;   /* +0x4c: 0 from the constructor */
    int unknown50;   /* +0x50: 0 from the constructor */
    int unknown54;   /* +0x54: 0 from the constructor */
    int unknown58;   /* +0x58: 0 from the constructor */
    u8 unknown5c[0x4];
    void *unknown60; /* +0x60: null from the constructor */
    int unknown68;   /* +0x68: 0 from the constructor */
    u8 unknown6c[0x4];
    Float4A unknown70; /* +0x70: zero from the constructor; not traced */
    float unknown80;   /* +0x80: negative infinity from the constructor */
    u8 unknown84[0xc];
    Float4A unknown90; /* +0x90: zero from the constructor; not traced */
    int unknowna0[8];  /* +0xa0: zero from the constructor; not traced */
    Float4A unknownc0; /* +0xc0: zero from the constructor; not traced */
    float unknownd0;   /* +0xd0: 0.0 from the constructor */
    int unknownd4;     /* +0xd4: 0 from the constructor */
    u8 unknownd8[0x8];
};

#endif
