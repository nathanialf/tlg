/* src/include/tlg_game_object016a8c70.h: the class whose vtable is at
 * 0x16a8c70 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8C70_H
#define TLG_GAME_OBJECT016A8C70_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8c70
 * (config/vtables.derived.base.txt, stored by its creator FUN_00378fb0, where
 * its constructor is inlined after Object016b9108's), derived from Object016b9108. 0xa0 bytes
 * (`mov edi, 0xa0` before operator new in the creator). Its fields are traced only where the creator sets them. The destructor is the class's key function (leaf_00379180.cpp). */
class Object016a8c70 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 0 at +0x24
     * and +0x28 (one eight-byte store), eight floats from +0x58 (one 32-byte
     * constant) and 7.0 at +0x78; then the body's state: 0 at +0x24 again,
     * zero at +0x2c to +0x34, +0x40, +0x50 and +0x80 to +0x88, -1.0 at +0x8c
     * and zero at +0x90 */
    Object016a8c70(const Name &name)
        : Object016b9108(name), unknown24(), unknown58(1.5f), unknown5c(2.0f), unknown60(160.0f),
          unknown64(210.0f), unknown68(90.0f), unknown6c(8.0f), unknown70(105.0f), unknown74(13.0f),
          unknown78(7.0f)
    {
        reset();
    }

    virtual ~Object016a8c70();

    void reset(); /* derived name: leaf_00379180.cpp */

  private:
    int unknown24
        [2]; /* +0x24: zero from the constructor (one eight-byte store); the first again from reset() */
    int unknown2c; /* +0x2c: 0 from the constructor */
    int unknown30; /* +0x30: 0 from the constructor */
    int unknown34; /* +0x34: 0 from the constructor */
    u8 unknown38[0x8];
    Float4A unknown40; /* +0x40: zero from the constructor; not traced */
    void *unknown50;   /* +0x50: null from the constructor; not traced */
    float unknown58;   /* +0x58: 1.5 from the constructor */
    float unknown5c;   /* +0x5c: 2.0 from the constructor */
    float unknown60;   /* +0x60: 160.0 from the constructor */
    float unknown64;   /* +0x64: 210.0 from the constructor */
    float unknown68;   /* +0x68: 90.0 from the constructor */
    float unknown6c;   /* +0x6c: 8.0 from the constructor */
    float unknown70;   /* +0x70: 105.0 from the constructor */
    float unknown74;   /* +0x74: 13.0 from the constructor */
    float unknown78;   /* +0x78: 7.0 from the constructor */
    u8 unknown7c[0x4];
    int unknown80;     /* +0x80: 0 from the constructor */
    int unknown84;     /* +0x84: 0 from the constructor */
    int unknown88;     /* +0x88: 0 from the constructor */
    float unknown8c;   /* +0x8c: -1.0 from the constructor */
    Float4A unknown90; /* +0x90: zero from the constructor; not traced */
};

#endif
