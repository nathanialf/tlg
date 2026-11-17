/* src/include/tlg_game_object016a8d50.h: the class whose vtable is at
 * 0x16a8d50 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8D50_H
#define TLG_GAME_OBJECT016A8D50_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8d50
 * (config/vtables.derived.base.txt, stored by its creator FUN_0037a460, where
 * its constructor is inlined after Object016b9108's), derived from Object016b9108. 0xa0 bytes
 * (`mov edi, 0xa0` before operator new in the creator). Its fields are traced only where the creator sets them. The destructor is the class's key function (leaf_0037a600.cpp). */
class Object016a8d50 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 0 at +0x24,
     * the 48 bytes from +0x30 cleared, 12.0, 15.0 and 1.0 at +0x60 and again
     * at +0x6c, and the 32 bytes from +0x80 cleared */
    Object016a8d50(const Name &name)
        : Object016b9108(name), unknown24(0), unknown30(), unknown60(12.0f), unknown64(15.0f),
          unknown68(1.0f), unknown6c(12.0f), unknown70(15.0f), unknown74(1.0f), unknown80()
    {
    }

    virtual ~Object016a8d50();

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    u8 unknown28[0x8];
    float unknown30[12]; /* +0x30: zero from the constructor; not traced */
    float unknown60;     /* +0x60: 12.0 from the constructor */
    float unknown64;     /* +0x64: 15.0 from the constructor */
    float unknown68;     /* +0x68: 1.0 from the constructor */
    float unknown6c;     /* +0x6c: 12.0 from the constructor */
    float unknown70;     /* +0x70: 15.0 from the constructor */
    float unknown74;     /* +0x74: 1.0 from the constructor */
    u8 unknown78[0x8];
    float unknown80[8]; /* +0x80: zero from the constructor; not traced */
};

#endif
