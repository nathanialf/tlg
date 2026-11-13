/* src/include/tlg_game_object016a7870.h: the class whose vtable is at
 * 0x16a7870 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7870_H
#define TLG_GAME_OBJECT016A7870_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16a7870
 * (config/vtables.derived.base.txt, stored by FUN_002188b0 FUN_0021bdf0
 * FUN_0021bf10), derived from Object016b9108: its slots 2 to 4 are the
 * base's, slots 5 to 8 its own (declared; their bodies are not written
 * here). 0x40 bytes (`mov edi, 0x40` before operator new at 0x2188c8). Its
 * own fields are traced where its creator FUN_002188b0 clears them and its
 * destructor FUN_0021bdf0 tears them down. */
class Object016a7870 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then `mov qword
     * [r15+0x28], 0; mov dword [r15+0x30], 0`, the vptr, `mov qword
     * [r15+0x38], 0` */
    Object016a7870(const Name &name) : Object016b9108(name), unknown28(0), unknown30(0) {}

    virtual ~Object016a7870();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    void *unknown28; /* +0x28: null from the constructor; not traced */
    int unknown30;   /* +0x30: zero from the constructor; not traced */
    /* +0x38: a counted reference, empty from the constructor, released by
     * the destructor (the pointer cleared, `cmp dword [r+8], 0xdeadc0de`,
     * the count dropped) */
    Ref00503fb0<Node00503fb0> held38;
};

/* derived name: the complete destructor FUN_0021bdf0: the body is empty; the
 * reference is released, then the base's destructor is inlined (its vptr
 * store, then the two names). FUN_0021bf10, slot 1, is the deleting one and
 * holds this one inlined. Defined here, so the unit that creates the object
 * (leaf_002188b0.cpp) emits the vtable and both destructors. */
inline Object016a7870::~Object016a7870() {}

#endif
