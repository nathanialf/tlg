/* src/include/tlg_game_object016b4450.h: the class whose vtable is at
 * 0x16b4450 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4450_H
#define TLG_GAME_OBJECT016B4450_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b4450
 * (config/vtables.derived.base.txt, stored by FUN_00af8800 FUN_00af8960
 * FUN_00af8a50), derived from Object016b9108. 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00af8800 sets them and its destructor FUN_00af8960
 * tears them down. */
class Object016b4450 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x2c], 0`
     * then `mov qword [r15+0x24], 0`: the two names are members, the int
     * before them is assigned in the body (the pair is merged where its later
     * store stands) */
    Object016b4450(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0;
    }

    virtual ~Object016b4450();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    Name name28;   /* +0x28: empty from the constructor, released by the destructor */
    Name name2c;   /* +0x2c: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_00af8960: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00af8a50, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00af8800.cpp)
 * emits the vtable and both destructors. */
inline Object016b4450::~Object016b4450() {}

#endif
