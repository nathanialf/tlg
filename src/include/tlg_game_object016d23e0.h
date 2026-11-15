/* src/include/tlg_game_object016d23e0.h: the class whose vtable is at
 * 0x16d23e0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D23E0_H
#define TLG_GAME_OBJECT016D23E0_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d23e0
 * (config/vtables.derived.base.txt, stored by FUN_00d57060 FUN_013b9b80
 * FUN_013b9c70), derived from Object016b9108. 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00d57060 sets them and its destructor FUN_013b9b80
 * tears them down. */
class Object016d23e0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x24],
     * 0xf` and `mov qword [r15+0x2c], 0` (two pairs, not one 16-byte store: the
     * four fields are not of one type), then bit 0 of the flags set */
    Object016d23e0(const Name &name) : Object016b9108(name), unknown24(15), unknown2c(0.0f)
    {
        flags |= 1;
    }

    virtual ~Object016d23e0();

  private:
    int unknown24;   /* +0x24: 15 from the constructor; not traced */
    Name name28;     /* +0x28: empty from the constructor, released by the destructor */
    float unknown2c; /* +0x2c: zero from the constructor; not traced */
    Name name30;     /* +0x30: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_013b9b80: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_013b9c70, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00d57060.cpp)
 * emits the vtable and both destructors. */
inline Object016d23e0::~Object016d23e0() {}

#endif
