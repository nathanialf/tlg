/* src/include/tlg_game_object016d1728.h: the class whose vtable is at
 * 0x16d1728 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1728_H
#define TLG_GAME_OBJECT016D1728_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d1728
 * (config/vtables.derived.base.txt, stored by FUN_00ca9000 FUN_013ad3b0
 * FUN_013ad4d0), derived from Object016b9108. 0x78 bytes (`mov edi,
 * 0x78` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00ca9000 sets them and its destructor FUN_013ad3b0
 * tears them down. */
class Object016d1728 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the ten floats
     * from +0x24 (eight in one 32-byte store from the constants at 0x14e8340,
     * then 4.0 and 0.1), `mov qword [r15+0x50], 0`, the eight floats from
     * +0x58 in two 16-byte stores (0x15447e0, 0x15447f0) */
    Object016d1728(const Name &name)
        : Object016b9108(name), unknown24(0.1f), unknown28(0.03f), unknown2c(0.6f), unknown30(4.0f),
          unknown34(4.0f), unknown38(0.1f), unknown3c(4.0f), unknown40(0.015f), unknown44(4.0f),
          unknown48(0.1f), unknown58(0.1f), unknown5c(0.5f), unknown60(0.95f), unknown64(0.7f),
          unknown68(0.5f), unknown6c(1.0f), unknown70(1.0f), unknown74(0.8f)
    {
    }

    virtual ~Object016d1728();

  private:
    float unknown24; /* +0x24: 0.1 from the constructor; not traced */
    float unknown28; /* +0x28: 0.03 from the constructor; not traced */
    float unknown2c; /* +0x2c: 0.6 from the constructor; not traced */
    float unknown30; /* +0x30: 4.0 from the constructor; not traced */
    float unknown34; /* +0x34: 4.0 from the constructor; not traced */
    float unknown38; /* +0x38: 0.1 from the constructor; not traced */
    float unknown3c; /* +0x3c: 4.0 from the constructor; not traced */
    float unknown40; /* +0x40: 0.015 from the constructor; not traced */
    float unknown44; /* +0x44: 4.0 from the constructor; not traced */
    float unknown48; /* +0x48: 0.1 from the constructor; not traced */
    /* +0x50: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held50;
    float unknown58; /* +0x58: 0.1 from the constructor; not traced */
    float unknown5c; /* +0x5c: 0.5 from the constructor; not traced */
    float unknown60; /* +0x60: 0.95 from the constructor; not traced */
    float unknown64; /* +0x64: 0.7 from the constructor; not traced */
    float unknown68; /* +0x68: 0.5 from the constructor; not traced */
    float unknown6c; /* +0x6c: 1.0 from the constructor; not traced */
    float unknown70; /* +0x70: 1.0 from the constructor; not traced */
    float unknown74; /* +0x74: 0.8 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_013ad3b0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_013ad4d0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00ca9000.cpp)
 * emits the vtable and both destructors. */
inline Object016d1728::~Object016d1728() {}

#endif
