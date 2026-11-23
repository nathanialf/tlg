/* src/include/tlg_game_object016b5380.h: the class whose vtable is at
 * 0x16b5380 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B5380_H
#define TLG_GAME_OBJECT016B5380_H

#include "tlg_game_node.h"
#include "tlg_game_object016b8d40.h"

/* derived names: the class whose vtable is at 0x16b5380
 * (config/vtables.derived.base.txt, stored by FUN_00b1f270 FUN_00b1f3e0
 * FUN_00b1f510), derived from Object016b8d40. 0x88 bytes (`mov edi,
 * 0x88` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b1f270 sets them and its destructor FUN_00b1f3e0
 * tears them down. The destructor is the class's key function
 * (leaf_00b1f3e0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b5380 : public Object016b8d40 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two references cleared in
     * one store (`vmovdqu [r15+0x58], xmm0`), the eight floats at +0x68 from the
     * constants at 0x14e5960 (3, 3, 0.467, 1.5, -0.8, 1, -3.2, 1) in one store */
    Object016b5380(const Name &name)
        : Object016b8d40(name), unknown68(3.0f), unknown6c(3.0f), unknown70(0.467f),
          unknown74(1.5f), unknown78(-0.8f), unknown7c(1.0f), unknown80(-3.2f), unknown84(1.0f)
    {
    }

    virtual ~Object016b5380();

  private:
    /* +0x58: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held58;
    /* +0x60: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held60;
    float unknown68; /* +0x68: 3.0 from the constructor; not traced */
    float unknown6c; /* +0x6c: 3.0 from the constructor; not traced */
    float unknown70; /* +0x70: 0.467 from the constructor; not traced */
    float unknown74; /* +0x74: 1.5 from the constructor; not traced */
    float unknown78; /* +0x78: -0.8 from the constructor; not traced */
    float unknown7c; /* +0x7c: 1.0 from the constructor; not traced */
    float unknown80; /* +0x80: -3.2 from the constructor; not traced */
    float unknown84; /* +0x84: 1.0 from the constructor; not traced */
};

#endif
