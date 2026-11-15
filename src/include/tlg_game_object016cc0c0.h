/* src/include/tlg_game_object016cc0c0.h: the class whose vtable is at
 * 0x16cc0c0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC0C0_H
#define TLG_GAME_OBJECT016CC0C0_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc0c0
 * (config/vtables.derived.base.txt, stored by FUN_0085e070 FUN_013712b0
 * FUN_01371370), derived from Object016b9108. 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_0085e070 sets them and its destructor FUN_013712b0
 * tears them down. */
class Object016cc0c0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 16 bytes cleared at +0x24
     * in one store: an int, the name and two ints (four 4-byte fields of one
     * type) */
    Object016cc0c0(const Name &name)
        : Object016b9108(name), unknown24(0), unknown2c(0), unknown30(0)
    {
    }

    virtual ~Object016cc0c0();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    Name name28;   /* +0x28: empty from the constructor, released by the destructor */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    int unknown30; /* +0x30: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_013712b0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01371370, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_0085e070.cpp)
 * emits the vtable and both destructors. */
inline Object016cc0c0::~Object016cc0c0() {}

#endif
