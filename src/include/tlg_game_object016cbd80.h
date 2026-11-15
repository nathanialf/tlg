/* src/include/tlg_game_object016cbd80.h: the class whose vtable is at
 * 0x16cbd80, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016CBD80_H
#define TLG_GAME_OBJECT016CBD80_H

#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16cbd80
 * (config/vtables.derived.base.txt, stored by FUN_007ae5c0 FUN_0136cbe0 FUN_0136cd30 and 4 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136d120 tears them down
 * (the Names at +0x84, +0x80); the rest are not traced. */
class Object016cbd80 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_007ae5c0: the int at +0x24, the two values
     * of ones at +0x30 (one 32-byte store), the box from the lowest to the
     * highest point and the origin (Float4 copies of the points of
     * tlg_math.h: one 16-byte integer vector each), the two names */
    Object016cbd80(const Name &name)
        : Object016b9108(name), unknown24(0), unknown30(1.0f, 1.0f, 1.0f, 1.0f),
          unknown40(1.0f, 1.0f, 1.0f, 1.0f), minimum50(FLOAT4_POINT_MIN),
          maximum60(FLOAT4_POINT_MAX), origin70(FLOAT4_POINT_ORIGIN)
    {
    }

    virtual ~Object016cbd80();

  private:
    int unknown24;     /* +0x24: zero from the constructor; not traced */
    Float4A unknown30; /* +0x30: ones from the constructor; not traced */
    Float4 unknown40;  /* +0x40: ones from the constructor; not traced */
    Float4 minimum50;  /* +0x50: the lowest point from the constructor; derived name */
    Float4 maximum60;  /* +0x60: the highest point from the constructor; derived name */
    Float4 origin70;   /* +0x70: the origin from the constructor; derived name */
    Name name80;       /* +0x80: released by the destructor (`mov eax, [rbx+0x80]; shl 5`) */
    Name name84;       /* +0x84: released by the destructor (`mov eax, [rbx+0x84]; shl 5`) */
};

/* derived name: the complete destructor (slot 0 of 0x16cbd80, FUN_0136d120): the
 * body is empty; the two Names are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0136d220,
 * slot 1, is the deleting one. Defined here, inline: the destructors of the
 * derived classes hold this body, and with no key function the class's
 * vtable and its two destructors are emitted by a unit that stores the
 * vtable (leaf_0136cbe0.cpp, the row's unit). */
inline Object016cbd80::~Object016cbd80() {}

#endif
