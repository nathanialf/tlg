/* src/include/tlg_game_object016ae220.h: the class whose vtable is at
 * 0x16ae220 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE220_H
#define TLG_GAME_OBJECT016AE220_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ae220
 * (config/vtables.derived.base.txt, stored by FUN_00805a40 FUN_00805bb0
 * FUN_00805ca0), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00805a40 sets them and its destructor FUN_00805bb0
 * tears them down. */
class Object016ae220 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 16 bytes cleared at +0x24
     * in one store (the two names and two ints), 1.0 at +0x34, `mov qword
     * [r15+0x38], 0` */
    Object016ae220(const Name &name)
        : Object016b9108(name), unknown2c(0), unknown30(0), unknown34(1.0f), unknown38(0)
    {
    }

    virtual ~Object016ae220();

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    Name name28;     /* +0x28: empty from the constructor, released by the destructor */
    int unknown2c;   /* +0x2c: zero from the constructor; not traced */
    int unknown30;   /* +0x30: zero from the constructor; not traced */
    float unknown34; /* +0x34: 1.0 from the constructor; not traced */
    void *unknown38; /* +0x38: null from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00805bb0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00805ca0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00805a40.cpp)
 * emits the vtable and both destructors. */
inline Object016ae220::~Object016ae220() {}

#endif
