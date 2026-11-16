/* src/include/tlg_game_object016a7870.h: the class whose vtable is at
 * 0x16a7870 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7870_H
#define TLG_GAME_OBJECT016A7870_H

#include "tlg_game_object01343880.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16a7870
 * (config/vtables.derived.base.txt, stored by FUN_002188b0 FUN_0021bdf0
 * FUN_0021bf10), derived from Object01343880: its slots 2 to 4 are
 * Object016b9108's, slots 5 to 8 Object01343880's. 0x40 bytes (`mov edi,
 * 0x40` before operator new at 0x2188c8). Its own field is traced where its
 * creator FUN_002188b0 clears it and its destructor FUN_0021bdf0 tears it
 * down. */
class Object016a7870 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name and its two
     * fields cleared, then the vptr, then `mov qword [r15+0x38], 0` */
    Object016a7870(const Name &name) : Object01343880(name) {}

    virtual ~Object016a7870();

  private:
    /* +0x38: a counted reference, empty from the constructor, released by
     * the destructor (the pointer cleared, `cmp dword [r+8], 0xdeadc0de`,
     * the count dropped) */
    Ref00503fb0<Object016b9108> held38;
};

/* derived name: the complete destructor FUN_0021bdf0: the body is empty; the
 * reference is released, then the base's destructor is inlined (its vptr
 * store, then the two names). FUN_0021bf10, slot 1, is the deleting one and
 * holds this one inlined. Defined here, so the unit that creates the object
 * (leaf_002188b0.cpp) emits the vtable and both destructors. */
inline Object016a7870::~Object016a7870() {}

#endif
