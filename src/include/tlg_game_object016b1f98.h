/* src/include/tlg_game_object016b1f98.h: the class whose vtable is at
 * 0x16b1f98 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1F98_H
#define TLG_GAME_OBJECT016B1F98_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16b1f98
 * (config/vtables.derived.base.txt, stored by FUN_00a521d0 FUN_00a52360
 * FUN_00a52420), derived from Object016b9108. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a521d0 sets them and its destructor FUN_00a52360
 * tears them down. */
class Object016b1f98 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword` 0 at +0x24 (the
     * name) and +0x28, 9999.0 at +0x2c, 1 at +0x30, the 16 bytes from +0x34
     * cleared (four ints, a run of zero stores made one memset), 1.0 at +0x44,
     * then the body's two floats at +0x48 in one `movabs` (1.0 and 0.6): the
     * 1.0 before them is not part of it, the two are one value assigned whole */
    Object016b1f98(const Name &name)
        : Object016b9108(name), unknown28(0), unknown2c(9999.0f), unknown30(1), unknown34(0),
          unknown38(0), unknown3c(0), unknown40(0), unknown44(1.0f)
    {
        unknown48 = Pair0057e850(1.0f, 0.6f);
    }

    virtual ~Object016b1f98();

  private:
    Name name24;            /* +0x24: empty from the constructor, released by the destructor */
    int unknown28;          /* +0x28: zero from the constructor; not traced */
    float unknown2c;        /* +0x2c: 9999.0 from the constructor; not traced */
    int unknown30;          /* +0x30: 1 from the constructor; not traced */
    int unknown34;          /* +0x34: zero from the constructor; not traced */
    int unknown38;          /* +0x38: zero from the constructor; not traced */
    int unknown3c;          /* +0x3c: zero from the constructor; not traced */
    int unknown40;          /* +0x40: zero from the constructor; not traced */
    float unknown44;        /* +0x44: 1.0 from the constructor; not traced */
    Pair0057e850 unknown48; /* +0x48: 1.0 and 0.6 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00a52360: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00a52420, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00a521d0.cpp)
 * emits the vtable and both destructors. */
inline Object016b1f98::~Object016b1f98() {}

#endif
