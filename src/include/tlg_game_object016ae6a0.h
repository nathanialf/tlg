/* src/include/tlg_game_object016ae6a0.h: the class whose vtable is at
 * 0x16ae6a0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE6A0_H
#define TLG_GAME_OBJECT016AE6A0_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16ae6a0
 * (config/vtables.derived.base.txt, stored by FUN_008181f0 FUN_00818360
 * FUN_00818450), derived from Object01343880: slots 7 and 8 override
 * the base's (FUN_00818540, FUN_00818720; declared, their bodies are not
 * members yet). 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008181f0 sets them and its destructor FUN_00818360
 * tears them down. */
class Object016ae6a0 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 16 bytes cleared at +0x34
     * in one store (two ints and the two names) */
    Object016ae6a0(const Name &name) : Object01343880(name), unknown34(0), unknown38(0) {}

    virtual ~Object016ae6a0();
    /* slot 7, FUN_00818540: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00818720: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();

  private:
    int unknown34; /* +0x34: zero from the constructor; not traced */
    int unknown38; /* +0x38: zero from the constructor; not traced */
    Name name3c;   /* +0x3c: empty from the constructor, released by the destructor */
    Name name40;   /* +0x40: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_00818360: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00818450, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_008181f0.cpp)
 * emits the vtable and both destructors. */
inline Object016ae6a0::~Object016ae6a0() {}

#endif
