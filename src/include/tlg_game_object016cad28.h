/* src/include/tlg_game_object016cad28.h: the class whose vtable is at
 * 0x16cad28 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CAD28_H
#define TLG_GAME_OBJECT016CAD28_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cad28
 * (config/vtables.derived.base.txt, stored by FUN_00429840 FUN_013509e0
 * FUN_01350aa0), derived from Object016b9108. 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00429840 sets them and its destructor FUN_013509e0
 * tears them down. */
class Object016cad28 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 16 bytes cleared at +0x24
     * in one store (the name and three ints), `mov dword [r15+0x34], 0` */
    Object016cad28(const Name &name)
        : Object016b9108(name), unknown28(0), unknown2c(0), unknown30(0), unknown34(0)
    {
    }

    virtual ~Object016cad28();

  private:
    Name name24;   /* +0x24: empty from the constructor, released by the destructor */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown34; /* +0x34: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_013509e0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01350aa0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00429840.cpp)
 * emits the vtable and both destructors. */
inline Object016cad28::~Object016cad28() {}

#endif
