/* src/include/tlg_game_object016cc298.h: the class whose vtable is at
 * 0x16cc298 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC298_H
#define TLG_GAME_OBJECT016CC298_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc298
 * (config/vtables.derived.base.txt, stored by FUN_00879080 FUN_01373240
 * FUN_01373330), derived from Object016b9108. 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00879080 sets them and its destructor FUN_01373240
 * tears them down. */
class Object016cc298 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 16 bytes cleared at +0x24
     * in one store (a name, an int, a name, an int), `mov dword [r15+0x34], 0` */
    Object016cc298(const Name &name)
        : Object016b9108(name), unknown28(0), unknown30(0), unknown34(0)
    {
    }

    virtual ~Object016cc298();

  private:
    Name name24;   /* +0x24: empty from the constructor, released by the destructor */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    Name name2c;   /* +0x2c: empty from the constructor, released by the destructor */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown34; /* +0x34: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_01373240: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01373330, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00879080.cpp)
 * emits the vtable and both destructors. */
inline Object016cc298::~Object016cc298() {}

#endif
