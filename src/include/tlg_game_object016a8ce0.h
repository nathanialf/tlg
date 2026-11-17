/* src/include/tlg_game_object016a8ce0.h: the class whose vtable is at
 * 0x16a8ce0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8CE0_H
#define TLG_GAME_OBJECT016A8CE0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8ce0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00379b40, where
 * its constructor is inlined after Object016b9108's), derived from Object016b9108. 0x80 bytes
 * (`mov edi, 0x80` before operator new in the creator). Its fields are traced only where the creator sets them. The destructor is the class's key function (leaf_00379ce0.cpp). */
class Object016a8ce0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 0 at +0x28,
     * 1.0 and 0 at +0x40, eight floats from +0x48 (one 32-byte constant);
     * the body's 0 at +0x24, zero at +0x30 and -1.0 four times from +0x68
     * come after the 32-byte store */
    Object016a8ce0(const Name &name)
        : Object016b9108(name), unknown28(0), unknown40(1.0f), unknown44(0), unknown48(0.0f),
          unknown4c(7.0f), unknown50(8.0f), unknown54(15.0f), unknown58(0.8f), unknown5c(1.0f),
          unknown60(0.5f), unknown64(1.0f)
    {
        unknown24 = 0;
        unknown30.set(0.0f, 0.0f, 0.0f, 0.0f);
        unknown68 = Float4(-1.0f, -1.0f, -1.0f, -1.0f);
    }

    virtual ~Object016a8ce0();

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    int unknown28; /* +0x28: 0 from the constructor */
    u8 unknown2c[0x4];
    Float4A unknown30; /* +0x30: zero from the constructor; not traced */
    float unknown40;   /* +0x40: 1.0 from the constructor */
    int unknown44;     /* +0x44: 0 from the constructor */
    float unknown48;   /* +0x48: 0.0 from the constructor */
    float unknown4c;   /* +0x4c: 7.0 from the constructor */
    float unknown50;   /* +0x50: 8.0 from the constructor */
    float unknown54;   /* +0x54: 15.0 from the constructor */
    float unknown58;   /* +0x58: 0.8 from the constructor */
    float unknown5c;   /* +0x5c: 1.0 from the constructor */
    float unknown60;   /* +0x60: 0.5 from the constructor */
    float unknown64;   /* +0x64: 1.0 from the constructor */
    Float4 unknown68;  /* +0x68: -1.0 in every lane from the constructor; not traced */
    u8 unknown78[0x8];
};

#endif
