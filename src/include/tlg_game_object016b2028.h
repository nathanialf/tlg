/* src/include/tlg_game_object016b2028.h: the class whose vtable is at
 * 0x16b2028 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B2028_H
#define TLG_GAME_OBJECT016B2028_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16b2028
 * (config/vtables.derived.base.txt, stored by FUN_00a52830 FUN_00a529f0
 * FUN_00a52ab0), derived from Object016b9108. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a52830 sets them and its destructor FUN_00a529f0
 * tears them down. */
class Object016b2028 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the four floats at +0x24 from
     * the constants at 0x153cd10 (0, 0, 0, 0.2) in one store, 1 at +0x34, the 16 bytes
     * from +0x38 cleared, 1.0 twice from +0x48 in one `movabs`, the name made from
     * "_Default" (FUN_013bad90, FUN_013baad0), 0.2 at +0x54, then the body's two
     * floats at +0x58 in one `movabs` (0.07 and 0.5): one value assigned whole */
    Object016b2028(const Name &name)
        : Object016b9108(name), unknown24(0.0f), unknown28(0.0f), unknown2c(0.0f), unknown30(0.2f),
          unknown34(1), unknown38(0), unknown3c(0), unknown40(0), unknown44(0), unknown48(1.0f),
          unknown4c(1.0f), name50("_Default", false), unknown54(0.2f)
    {
        unknown58 = Pair0057e850(0.07f, 0.5f);
    }

    virtual ~Object016b2028();

  private:
    float unknown24; /* +0x24: zero from the constructor; not traced */
    float unknown28; /* +0x28: zero from the constructor; not traced */
    float unknown2c; /* +0x2c: zero from the constructor; not traced */
    float unknown30; /* +0x30: 0.2 from the constructor; not traced */
    int unknown34;   /* +0x34: 1 from the constructor; not traced */
    int unknown38;   /* +0x38: zero from the constructor; not traced */
    int unknown3c;   /* +0x3c: zero from the constructor; not traced */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    int unknown44;   /* +0x44: zero from the constructor; not traced */
    float unknown48; /* +0x48: 1.0 from the constructor; not traced */
    float unknown4c; /* +0x4c: 1.0 from the constructor; not traced */
    Name
        name50; /* +0x50: "_Default" from the constructor (interned, not added), released by the destructor */
    float unknown54;        /* +0x54: 0.2 from the constructor; not traced */
    Pair0057e850 unknown58; /* +0x58: 0.07 and 0.5 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00a529f0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00a52ab0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00a52830.cpp)
 * emits the vtable and both destructors. */
inline Object016b2028::~Object016b2028() {}

#endif
