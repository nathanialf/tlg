/* src/include/tlg_game_object016bd520.h: the class whose vtable is at
 * 0x16bd520 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BD520_H
#define TLG_GAME_OBJECT016BD520_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd520
 * (config/vtables.derived.base.txt, stored by FUN_00dff490 FUN_00e01530
 * FUN_00e015f0), derived from Object016b9108. 0x78 bytes (`mov edi,
 * 0x78` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00dff490 sets them and its destructor FUN_00e01530
 * tears them down. */
class Object016bd520 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 20 bytes cleared at +0x28
     * (four floats and the name: `vmovups [r15+0x28], xmm0; mov dword
     * [r15+0x38], 0`), then the 56 bytes from +0x40 to the object's end (seven
     * 8-byte fields: two 32-byte stores that overlap, the last one first):
     * two runs of zero stores the compiler made memsets, in this order;
     * +0x24 is not written */
    Object016bd520(const Name &name)
        : Object016b9108(name), unknown28(0.0f), unknown2c(0.0f), unknown30(0.0f), unknown34(0.0f),
          unknown40(0), unknown48(0), unknown50(0), unknown58(0), unknown60(0), unknown68(0),
          unknown70(0)
    {
    }

    virtual ~Object016bd520();

  private:
    int unknown24;   /* +0x24: not written by the constructor; not traced */
    float unknown28; /* +0x28: zero from the constructor; not traced */
    float unknown2c; /* +0x2c: zero from the constructor; not traced */
    float unknown30; /* +0x30: zero from the constructor; not traced */
    float unknown34; /* +0x34: zero from the constructor; not traced */
    Name name38;     /* +0x38: empty from the constructor, released by the destructor */
    u64 unknown40;   /* +0x40: zero from the constructor; not traced */
    u64 unknown48;   /* +0x48: zero from the constructor; not traced */
    u64 unknown50;   /* +0x50: zero from the constructor; not traced */
    u64 unknown58;   /* +0x58: zero from the constructor; not traced */
    u64 unknown60;   /* +0x60: zero from the constructor; not traced */
    u64 unknown68;   /* +0x68: zero from the constructor; not traced */
    u64 unknown70;   /* +0x70: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00e01530: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00e015f0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00dff490.cpp)
 * emits the vtable and both destructors. */
inline Object016bd520::~Object016bd520() {}

#endif
