/* src/include/tlg_game_object016d1668.h: the class whose vtable is at
 * 0x16d1668 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1668_H
#define TLG_GAME_OBJECT016D1668_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d1668
 * (config/vtables.derived.base.txt, stored by FUN_00c91f20 FUN_013abbe0
 * FUN_013abd00), derived from Object016b9108: its five slots are the two
 * destructors and the base's three. Its own fields are traced where its
 * constructor FUN_00c91f20 sets them and its destructor FUN_013abbe0 tears
 * them down. */
class Object016d1668 : public Object016b9108 /* derived name */
{
  public:
    Object016d1668(const Name &name); /* FUN_00c91f20 */
    virtual ~Object016d1668();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    /* +0x30: a counted reference set by compare-and-swap in the constructor
     * (`lock cmpxchg qword [r14+0x30], rcx` at 0xc91f5c), released by the
     * destructor (the pointer cleared, `cmp dword [r+8], 0xdeadc0de`, the
     * count dropped) */
    AtomicRef0045c470<Node00503fb0> held30;
};

/* derived name: the complete destructor FUN_013abbe0: the body is empty; the
 * reference is released, then the base's destructor is inlined (its vptr
 * store, then the two names). FUN_013abd00, slot 1, is the deleting one and
 * holds this one inlined. Defined here, so the unit that defines the
 * constructor (leaf_00c91f20.cpp) emits the vtable and both destructors. */
inline Object016d1668::~Object016d1668() {}

#endif
