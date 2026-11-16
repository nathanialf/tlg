/* src/include/tlg_game_object016ce378.h: the class whose vtable is at
 * 0x16ce378 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE378_H
#define TLG_GAME_OBJECT016CE378_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ce378
 * (config/vtables.derived.base.txt, stored by FUN_00a54400 FUN_0138cf00
 * FUN_0138d020), derived from Object016b9108. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a54400 sets them and its destructor FUN_0138cf00
 * tears them down. */
class Object016ce378 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the twelve floats
     * from +0x24 (eight in one 32-byte store from the constants at 0x14e5540,
     * four in a 16-byte one from 0x153cd40), `mov qword [r15+0x58], 0` */
    Object016ce378(const Name &name)
        : Object016b9108(name), unknown24(0.4f), unknown28(0.7f), unknown2c(1.0f), unknown30(0.0f),
          unknown34(2000.0f), unknown38(1500.0f), unknown3c(100.0f), unknown40(200.0f),
          unknown44(100.0f), unknown48(300.0f), unknown4c(30.0f), unknown50(0.3f)
    {
    }

    virtual ~Object016ce378();

  private:
    float unknown24; /* +0x24: 0.4 from the constructor; not traced */
    float unknown28; /* +0x28: 0.7 from the constructor; not traced */
    float unknown2c; /* +0x2c: 1.0 from the constructor; not traced */
    float unknown30; /* +0x30: 0.0 from the constructor; not traced */
    float unknown34; /* +0x34: 2000.0 from the constructor; not traced */
    float unknown38; /* +0x38: 1500.0 from the constructor; not traced */
    float unknown3c; /* +0x3c: 100.0 from the constructor; not traced */
    float unknown40; /* +0x40: 200.0 from the constructor; not traced */
    float unknown44; /* +0x44: 100.0 from the constructor; not traced */
    float unknown48; /* +0x48: 300.0 from the constructor; not traced */
    float unknown4c; /* +0x4c: 30.0 from the constructor; not traced */
    float unknown50; /* +0x50: 0.3 from the constructor; not traced */
    /* +0x58: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held58;
};

/* derived name: the complete destructor FUN_0138cf00: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_0138d020, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00a54400.cpp)
 * emits the vtable and both destructors. */
inline Object016ce378::~Object016ce378() {}

#endif
