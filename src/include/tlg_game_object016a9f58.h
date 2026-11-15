/* src/include/tlg_game_object016a9f58.h: the class whose vtable is at
 * 0x16a9f58 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9F58_H
#define TLG_GAME_OBJECT016A9F58_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the name the constructor copies to +0x64 (func_004aa8c0.cpp) */
extern Name D_57d7338;

/* derived names: the class whose vtable is at 0x16a9f58
 * (config/vtables.derived.base.txt, stored by FUN_004a9fb0 FUN_004aa160
 * FUN_004aa220), derived from Object016b9108. 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_004a9fb0 sets them and its destructor FUN_004aa160
 * tears them down. */
class Object016a9f58 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword` 0, 1.0, 0, 0 from
     * +0x24 (an int, a float and two ints: not four of one type), the eight
     * floats at +0x40 from the constants at 0x14e3c60 (0, 0, 0, 1 twice) in one
     * store, `mov dword [r15+0x60], 0`, then the name at +0x64 copied from the
     * one at 0x57d7338 (`lock inc` of its count, the index read again) */
    Object016a9f58(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(1.0f), unknown2c(0), unknown30(0),
          unknown40(0.0f), unknown44(0.0f), unknown48(0.0f), unknown4c(1.0f), unknown50(0.0f),
          unknown54(0.0f), unknown58(0.0f), unknown5c(1.0f), unknown60(0), name64(D_57d7338)
    {
    }

    virtual ~Object016a9f58();

  private:
    int unknown24;   /* +0x24: zero from the constructor; not traced */
    float unknown28; /* +0x28: 1.0 from the constructor; not traced */
    int unknown2c;   /* +0x2c: zero from the constructor; not traced */
    int unknown30;   /* +0x30: zero from the constructor; not traced */
    u8 unknown34[0xc];
    float unknown40; /* +0x40: zero from the constructor; not traced */
    float unknown44; /* +0x44: zero from the constructor; not traced */
    float unknown48; /* +0x48: zero from the constructor; not traced */
    float unknown4c; /* +0x4c: 1.0 from the constructor; not traced */
    float unknown50; /* +0x50: zero from the constructor; not traced */
    float unknown54; /* +0x54: zero from the constructor; not traced */
    float unknown58; /* +0x58: zero from the constructor; not traced */
    float unknown5c; /* +0x5c: 1.0 from the constructor; not traced */
    int unknown60;   /* +0x60: zero from the constructor; not traced */
    Name name64;     /* +0x64: a copy of the name at 0x57d7338, released by the destructor */
    u8 unknown68[0x8];
};

/* derived name: the complete destructor FUN_004aa160: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_004aa220, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_004a9fb0.cpp)
 * emits the vtable and both destructors. */
inline Object016a9f58::~Object016a9f58() {}

#endif
