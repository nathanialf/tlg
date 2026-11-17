/* src/include/tlg_game_object016a7ce8.h: the class whose vtable is at
 * 0x16a7ce8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7CE8_H
#define TLG_GAME_OBJECT016A7CE8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16a7ce8
 * (config/vtables.derived.base.txt, stored by its creator FUN_002a8650, where
 * its constructor is inlined, and by its destructors 0x2a87b0 and 0x2a8810),
 * derived from Object016b85e0 (the creator calls that class's constructor
 * 0xc55320 first). 0x240 bytes (`mov edi, 0x240` before operator new in the
 * creator). The destructor releases its Name at +0x23c, then tail-calls its
 * base's destructor (0xc55550); it is the class's key function, so
 * leaf_002a87b0.cpp emits the vtable. The other members are not traced. */
class Object016a7ce8 : public Object016b85e0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then zero at
     * +0x238 and the empty Name at +0x23c (one eight-byte store) */
    Object016a7ce8(const Name &name) : Object016b85e0(name), unknown238(0) {}

    virtual ~Object016a7ce8();

  private:
    u8 unknown8[0x230];
    int unknown238; /* +0x238: 0 from the constructor; not traced */
    Name name23c;   /* +0x23c */
};

#endif
