/* src/include/tlg_game_object016b0178.h: the class whose vtable is at
 * 0x16b0178 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0178_H
#define TLG_GAME_OBJECT016B0178_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0178
 * (config/vtables.derived.base.txt, stored by FUN_008c0fe0 FUN_008c1140
 * FUN_008c1230), derived from Object016b9108: slot 5 is its own
 * (0x42d0, a body the linker folded with a library function's; declared). 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008c0fe0 sets them and its destructor FUN_008c1140
 * tears them down. */
class Object016b0178 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 16 bytes at +0x24 from
     * the constants at 0x1539220 (0, 999999, 0, 0: two ints and the two names,
     * four 4-byte fields of one type) */
    Object016b0178(const Name &name) : Object016b9108(name), unknown24(0), unknown28(999999) {}

    virtual ~Object016b0178();
    virtual void slot5(); /* derived name; FUN_000042d0, not traced */

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    int unknown28; /* +0x28: 999999 from the constructor; not traced */
    Name name2c;   /* +0x2c: empty from the constructor, released by the destructor */
    Name name30;   /* +0x30: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_008c1140: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_008c1230, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_008c0fe0.cpp)
 * emits the vtable and both destructors. */
inline Object016b0178::~Object016b0178() {}

#endif
