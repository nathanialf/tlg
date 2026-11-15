/* src/include/tlg_game_object016b19f0.h: the class whose vtable is at
 * 0x16b19f0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B19F0_H
#define TLG_GAME_OBJECT016B19F0_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b19f0
 * (config/vtables.derived.base.txt, stored by FUN_009f5dd0 FUN_009f6990
 * FUN_009f6ab0), derived from Object01343880: slots 5, 7 and 8 override
 * the base's (FUN_009f6bc0, FUN_009f6ca0, FUN_009f6cc0; declared, their
 * bodies are not members yet). 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009f5dd0 sets them and its destructor FUN_009f6990
 * tears them down. */
class Object016b19f0 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword
     * [r15+0x34], 0`, `mov dword [r15+0x38], 0`, `mov qword [r15+0x40], 0` */
    Object016b19f0(const Name &name) : Object01343880(name), unknown34(0), unknown38(0) {}

    virtual ~Object016b19f0();
    /* slot 5, FUN_009f6bc0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();
    /* slot 7, FUN_009f6ca0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_009f6cc0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();

  private:
    int unknown34; /* +0x34: zero from the constructor; not traced */
    int unknown38; /* +0x38: zero from the constructor; not traced */
    /* +0x40: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held40;
};

/* derived name: the complete destructor FUN_009f6990: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_009f6ab0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_009f5dd0.cpp)
 * emits the vtable and both destructors. */
inline Object016b19f0::~Object016b19f0() {}

#endif
