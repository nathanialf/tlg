/* src/include/tlg_game_object016b70b0.h: the class whose vtable is at
 * 0x16b70b0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B70B0_H
#define TLG_GAME_OBJECT016B70B0_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b70b0
 * (config/vtables.derived.base.txt, stored by FUN_00b87da0 FUN_00b88500
 * FUN_00b885c0), derived from Object01343880: slot 5 overrides the
 * base's (FUN_00b88680; declared, its body is not a member yet). 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b87da0 sets them and its destructor FUN_00b88500
 * tears them down. */
class Object016b70b0 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x34], 0` */
    Object016b70b0(const Name &name) : Object01343880(name) {}

    virtual ~Object016b70b0();
    /* slot 5, FUN_00b88680: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();

  private:
    Name name34; /* +0x34: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_00b88500: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00b885c0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00b87da0.cpp)
 * emits the vtable and both destructors. */
inline Object016b70b0::~Object016b70b0() {}

#endif
