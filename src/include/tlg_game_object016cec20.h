/* src/include/tlg_game_object016cec20.h: the class whose vtable is at
 * 0x16cec20 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CEC20_H
#define TLG_GAME_OBJECT016CEC20_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16cec20
 * (config/vtables.derived.base.txt, stored by FUN_00b0c950 FUN_0138f790
 * FUN_0138f8b0), derived from Object016b9108: its five slots are the two
 * destructors and the base's three. 0x38 bytes (`mov edi,
 * 0x38` before operator new at 0xb0c968).
 * Its own fields are traced where its creator FUN_00b0c950 sets them and
 * its destructor FUN_0138f790 tears them down. */
class Object016cec20 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov
     * dword [r15+0x24], 2; mov qword [r15+0x28], 0`, then the two floats in
     * one store (`movabs rdx, 0x4120000040000000`) */
    Object016cec20(const Name &name)
        : Object016b9108(name), unknown24(2), unknown30(2.0f), unknown34(10.0f)
    {
    }

    virtual ~Object016cec20();

  private:
    int unknown24; /* +0x24: 2 from the constructor; not traced */
    /* +0x28: a counted reference, empty from the constructor, released by
     * the destructor (the pointer cleared, `cmp dword [r+8], 0xdeadc0de`,
     * the count dropped) */
    Ref00503fb0<Object016b9108> held28;
    float unknown30; /* +0x30: 2.0 from the constructor; not traced */
    float unknown34; /* +0x34: 10.0 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_0138f790: the body is empty; the
 * reference is released, then the base's destructor is inlined (its vptr
 * store, then the two names). FUN_0138f8b0, slot 1, is the deleting one and
 * holds this one inlined. Defined here, so the unit that creates the object
 * (leaf_00b0c950.cpp) emits the vtable and both destructors. */
inline Object016cec20::~Object016cec20() {}

#endif
