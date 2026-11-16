/* src/include/tlg_game_object016cec90.h: the class whose vtable is at
 * 0x16cec90 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CEC90_H
#define TLG_GAME_OBJECT016CEC90_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16cec90
 * (config/vtables.derived.base.txt, stored by FUN_00b0d680 FUN_0138fb20
 * FUN_0138fc40), derived from Object016b9108: its five slots are the two
 * destructors and the base's three. 0x40 bytes (`mov edi,
 * 0x40` before operator new at 0xb0d698).
 * Its own fields are traced where its creator FUN_00b0d680 sets them and
 * its destructor FUN_0138fb20 tears them down. */
class Object016cec90 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov
     * qword [r15+0x28], 0`, then the four values in one 16-byte store from
     * the constants at 0x1540630 (2.0, 0, 10.0, 0) */
    Object016cec90(const Name &name)
        : Object016b9108(name), unknown30(2.0f), unknown34(0.0f), unknown38(10.0f), unknown3c(0.0f)
    {
    }

    virtual ~Object016cec90();

  private:
    /* +0x28: a counted reference, empty from the constructor, released by
     * the destructor (the pointer cleared, `cmp dword [r+8], 0xdeadc0de`,
     * the count dropped) */
    Ref00503fb0<Object016b9108> held28;
    float unknown30; /* +0x30: 2.0 from the constructor; not traced */
    float unknown34; /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 10.0 from the constructor; not traced */
    float unknown3c; /* +0x3c: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_0138fb20: the body is empty; the
 * reference is released, then the base's destructor is inlined (its vptr
 * store, then the two names). FUN_0138fc40, slot 1, is the deleting one and
 * holds this one inlined. Defined here, so the unit that creates the object
 * (leaf_00b0d680.cpp) emits the vtable and both destructors. */
inline Object016cec90::~Object016cec90() {}

#endif
