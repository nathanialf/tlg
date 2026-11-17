/* src/include/tlg_game_object016a9200.h: the class whose vtable is at
 * 0x16a9200 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9200_H
#define TLG_GAME_OBJECT016A9200_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9200
 * (config/vtables.derived.base.txt, stored by its creator FUN_003e7730, where
 * its constructor is inlined after Object016b9108's), derived from Object016b9108. 0xb0 bytes
 * (`mov edi, 0xb0` before operator new in the creator). Its fields are traced only where the creator sets them. The destructor is the class's key function (leaf_003e78d0.cpp). */
class Object016a9200 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, zero from
     * +0x30 to +0x44 and from +0x50 to +0x60, 1.0 at +0x60 and +0x64, zero
     * at +0x68 and +0x70, and the 48 bytes from +0x80 cleared */
    Object016a9200(const Name &name)
        : Object016b9108(name), unknown30(0.0f, 0.0f, 0.0f, 0.0f), unknown40(0),
          unknown50(0.0f, 0.0f, 0.0f, 0.0f), unknown60(1.0f), unknown64(1.0f), unknown68(0),
          unknown70(0), unknown80()
    {
    }

    virtual ~Object016a9200();

  private:
    u8 unknown24[0xc];
    Float4 unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown40;    /* +0x40: 0 from the constructor */
    u8 unknown44[0xc];
    Float4 unknown50; /* +0x50: zero from the constructor; not traced */
    float unknown60;  /* +0x60: 1.0 from the constructor */
    float unknown64;  /* +0x64: 1.0 from the constructor */
    void *unknown68;  /* +0x68: null from the constructor; not traced */
    int unknown70;    /* +0x70: 0 from the constructor */
    u8 unknown74[0xc];
    void *unknown80[6]; /* +0x80: null from the constructor; not traced */
};

#endif
