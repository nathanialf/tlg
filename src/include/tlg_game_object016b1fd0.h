/* src/include/tlg_game_object016b1fd0.h: the class whose vtable is at
 * 0x16b1fd0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1FD0_H
#define TLG_GAME_OBJECT016B1FD0_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16b1fd0
 * (config/vtables.derived.base.txt, stored by FUN_00a524e0 FUN_00a526b0
 * FUN_00a52770), derived from Object01343880. 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a524e0 sets them and its destructor FUN_00a526b0
 * tears them down. */
class Object016b1fd0 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the four floats at +0x34 from
     * the constants at 0x153cd00 (0, 0, 0, 0.2) in one store, 1 at +0x44, the 16 bytes
     * from +0x48 cleared, 1.0 twice from +0x58 in one `movabs`, the name made from
     * "_Default" (FUN_013bad90, FUN_013baad0), 0.2 at +0x64, then the body's two
     * floats at +0x68 in one `movabs` (0.07 and 0.5): one value assigned whole */
    Object016b1fd0(const Name &name)
        : Object01343880(name), unknown34(0.0f), unknown38(0.0f), unknown3c(0.0f), unknown40(0.2f),
          unknown44(1), unknown48(0), unknown4c(0), unknown50(0), unknown54(0), unknown58(1.0f),
          unknown5c(1.0f), name60("_Default", false), unknown64(0.2f)
    {
        unknown68 = Pair0057e850(0.07f, 0.5f);
    }

    virtual ~Object016b1fd0();

  private:
    float unknown34; /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: zero from the constructor; not traced */
    float unknown3c; /* +0x3c: zero from the constructor; not traced */
    float unknown40; /* +0x40: 0.2 from the constructor; not traced */
    int unknown44;   /* +0x44: 1 from the constructor; not traced */
    int unknown48;   /* +0x48: zero from the constructor; not traced */
    int unknown4c;   /* +0x4c: zero from the constructor; not traced */
    int unknown50;   /* +0x50: zero from the constructor; not traced */
    int unknown54;   /* +0x54: zero from the constructor; not traced */
    float unknown58; /* +0x58: 1.0 from the constructor; not traced */
    float unknown5c; /* +0x5c: 1.0 from the constructor; not traced */
    Name
        name60; /* +0x60: "_Default" from the constructor (interned, not added), released by the destructor */
    float unknown64;        /* +0x64: 0.2 from the constructor; not traced */
    Pair0057e850 unknown68; /* +0x68: 0.07 and 0.5 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00a526b0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00a52770, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00a524e0.cpp)
 * emits the vtable and both destructors. */
inline Object016b1fd0::~Object016b1fd0() {}

#endif
