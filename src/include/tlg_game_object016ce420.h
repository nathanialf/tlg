/* src/include/tlg_game_object016ce420.h: the class whose vtable is at
 * 0x16ce420 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE420_H
#define TLG_GAME_OBJECT016CE420_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ce420
 * (config/vtables.derived.base.txt, stored by FUN_00a63d50 FUN_0138d130
 * FUN_0138d220), derived from Object016b9108. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a63d50 sets them and its destructor FUN_0138d130
 * tears them down. */
class Object016ce420 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x24], 0`,
     * 32 bytes cleared at +0x2c in one store (the second name and seven ints:
     * eight 4-byte fields of one type); +0x28 is not written */
    Object016ce420(const Name &name)
        : Object016b9108(name), unknown30(0), unknown34(0), unknown38(0), unknown3c(0),
          unknown40(0), unknown44(0), unknown48(0)
    {
    }

    virtual ~Object016ce420();

  private:
    Name name24;   /* +0x24: empty from the constructor, released by the destructor */
    int unknown28; /* +0x28: not written by the constructor; not traced */
    Name name2c;   /* +0x2c: empty from the constructor, released by the destructor */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown34; /* +0x34: zero from the constructor; not traced */
    int unknown38; /* +0x38: zero from the constructor; not traced */
    int unknown3c; /* +0x3c: zero from the constructor; not traced */
    int unknown40; /* +0x40: zero from the constructor; not traced */
    int unknown44; /* +0x44: zero from the constructor; not traced */
    int unknown48; /* +0x48: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_0138d130: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_0138d220, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00a63d50.cpp)
 * emits the vtable and both destructors. */
inline Object016ce420::~Object016ce420() {}

#endif
