/* src/include/tlg_game_object016b1f40.h: the class whose vtable is at
 * 0x16b1f40 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1F40_H
#define TLG_GAME_OBJECT016B1F40_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16b1f40
 * (config/vtables.derived.base.txt, stored by FUN_00a51eb0 FUN_00a52050
 * FUN_00a52110), derived from Object01343880. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a51eb0 sets them and its destructor FUN_00a52050
 * tears them down. The destructor is the class's key function
 * (leaf_00a52050.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b1f40 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the name, 0 at +0x38,
     * 9999.0 at +0x3c, 1 at +0x40, the 16 bytes from +0x44 cleared in one store
     * (four ints, a run of zero stores made one memset), 1.0 at +0x54, then the
     * body's 1.0 and 0.6 at +0x58 in one `movabs` that the 1.0 before it is
     * not part of (one value of two floats, assigned whole); the base's pointer
     * and int cleared before the vptr store */
    Object016b1f40(const Name &name)
        : Object01343880(name), unknown38(0), unknown3c(9999.0f), unknown40(1), unknown44(0),
          unknown48(0), unknown4c(0), unknown50(0), unknown54(1.0f)
    {
        unknown58 = Pair0057e850(1.0f, 0.6f);
    }

    virtual ~Object016b1f40();

  private:
    Name name34;            /* +0x34: empty from the constructor, released by the destructor */
    int unknown38;          /* +0x38: zero from the constructor; not traced */
    float unknown3c;        /* +0x3c: 9999.0 from the constructor; not traced */
    int unknown40;          /* +0x40: 1 from the constructor; not traced */
    int unknown44;          /* +0x44: zero from the constructor; not traced */
    int unknown48;          /* +0x48: zero from the constructor; not traced */
    int unknown4c;          /* +0x4c: zero from the constructor; not traced */
    int unknown50;          /* +0x50: zero from the constructor; not traced */
    float unknown54;        /* +0x54: 1.0 from the constructor; not traced */
    Pair0057e850 unknown58; /* +0x58: 1.0 and 0.6 from the constructor; not traced */
};

#endif
