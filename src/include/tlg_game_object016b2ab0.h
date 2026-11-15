/* src/include/tlg_game_object016b2ab0.h: the class whose vtable is at
 * 0x16b2ab0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B2AB0_H
#define TLG_GAME_OBJECT016B2AB0_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b2ab0
 * (config/vtables.derived.base.txt, stored by FUN_00a94ed0 FUN_00a95030
 * FUN_00a95120), derived from Object016b9108. 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a94ed0 sets them and its destructor FUN_00a95030
 * tears them down. */
class Object016b2ab0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x24], 0`: the
     * two names */
    Object016b2ab0(const Name &name) : Object016b9108(name) {}

    virtual ~Object016b2ab0();

  private:
    Name name24; /* +0x24: empty from the constructor, released by the destructor */
    Name name28; /* +0x28: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_00a95030: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00a95120, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00a94ed0.cpp)
 * emits the vtable and both destructors. */
inline Object016b2ab0::~Object016b2ab0() {}

#endif
