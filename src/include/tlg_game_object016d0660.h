/* src/include/tlg_game_object016d0660.h: the class whose vtable is at
 * 0x16d0660 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D0660_H
#define TLG_GAME_OBJECT016D0660_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d0660
 * (config/vtables.derived.base.txt, stored by FUN_00c23b00 FUN_013a2af0
 * FUN_013a2bb0), derived from Object016b9108. 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00c23b00 sets them and its destructor FUN_013a2af0
 * tears them down. */
class Object016d0660 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `movabs rdx,
     * 0xffffffff00000000` stored at +0x24 (the name and -1), `mov dword
     * [r15+0x2c], 0` */
    Object016d0660(const Name &name) : Object016b9108(name), unknown28(-1), unknown2c(0) {}

    virtual ~Object016d0660();

  private:
    Name name24;   /* +0x24: empty from the constructor, released by the destructor */
    int unknown28; /* +0x28: -1 from the constructor; not traced */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_013a2af0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_013a2bb0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00c23b00.cpp)
 * emits the vtable and both destructors. */
inline Object016d0660::~Object016d0660() {}

#endif
