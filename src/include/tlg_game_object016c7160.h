/* src/include/tlg_game_object016c7160.h: the class whose vtable is at
 * 0x16c7160 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7160_H
#define TLG_GAME_OBJECT016C7160_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7160
 * (config/vtables.derived.base.txt, stored by FUN_00218a20 FUN_013470b0
 * FUN_01347170), derived from Object016b9108. 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00218a20 sets them and its destructor FUN_013470b0
 * tears them down. */
class Object016c7160 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 16 bytes cleared at +0x24
     * in one store (four ints), `mov dword [r15+0x34], 0` (the name) */
    Object016c7160(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown2c(0), unknown30(0)
    {
    }

    virtual ~Object016c7160();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    Name name34;   /* +0x34: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_013470b0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01347170, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00218a20.cpp)
 * emits the vtable and both destructors. */
inline Object016c7160::~Object016c7160() {}

#endif
