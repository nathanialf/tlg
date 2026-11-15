/* src/include/tlg_game_object016cabf0.h: the class whose vtable is at
 * 0x16cabf0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CABF0_H
#define TLG_GAME_OBJECT016CABF0_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cabf0
 * (config/vtables.derived.base.txt, stored by FUN_004077f0 FUN_01350190
 * FUN_01350250), derived from Object016b9108. 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its own fields are traced
 * where its creator FUN_004077f0 sets them and its destructor FUN_01350190
 * tears them down. */
class Object016cabf0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x24], 0`: the
     * name and an int after it */
    Object016cabf0(const Name &name) : Object016b9108(name), unknown28(0) {}

    virtual ~Object016cabf0();

  private:
    Name name24;   /* +0x24: empty from the constructor, released by the destructor */
    int unknown28; /* +0x28: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_01350190: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01350250, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_004077f0.cpp)
 * emits the vtable and both destructors. */
inline Object016cabf0::~Object016cabf0() {}

#endif
