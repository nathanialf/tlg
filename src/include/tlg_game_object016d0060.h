/* src/include/tlg_game_object016d0060.h: the class whose vtable is at
 * 0x16d0060 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D0060_H
#define TLG_GAME_OBJECT016D0060_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d0060
 * (config/vtables.derived.base.txt, stored by FUN_00b49c30 FUN_0139be10
 * FUN_0139bf00), derived from Object016b9108. 0x88 bytes (`mov edi,
 * 0x88` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b49c30 sets them and its destructor FUN_0139be10
 * tears them down. */
class Object016d0060 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 16 bytes at +0x24 from
     * the constants at 0x15412f0 (the two names, 1, 1: four 4-byte fields of one
     * type), `mov dword` stores from +0x34 (0, 1, 1, 1.0, 1.0, 1.0, 1, 1.0, 1.0),
     * 1.0 and 1 at +0x58 in one `movabs`, the 40 bytes from +0x60 cleared
     * (`vmovups [rbx+0x60], ymm0; mov qword [rbx+0x80], 0`: a run of zero
     * stores made one memset) */
    Object016d0060(const Name &name)
        : Object016b9108(name), unknown2c(1), unknown30(1), unknown34(0), unknown38(1),
          unknown3c(1), unknown40(1.0f), unknown44(1.0f), unknown48(1.0f), unknown4c(1),
          unknown50(1.0f), unknown54(1.0f), unknown58(1.0f), unknown5c(1), unknown60(0),
          unknown64(0), unknown68(0), unknown6c(0), unknown70(0), unknown74(0), unknown78(0),
          unknown7c(0), unknown80(0), unknown84(0)
    {
    }

    virtual ~Object016d0060();

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    Name name28;     /* +0x28: empty from the constructor, released by the destructor */
    int unknown2c;   /* +0x2c: 1 from the constructor; not traced */
    int unknown30;   /* +0x30: 1 from the constructor; not traced */
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    int unknown38;   /* +0x38: 1 from the constructor; not traced */
    int unknown3c;   /* +0x3c: 1 from the constructor; not traced */
    float unknown40; /* +0x40: 1.0 from the constructor; not traced */
    float unknown44; /* +0x44: 1.0 from the constructor; not traced */
    float unknown48; /* +0x48: 1.0 from the constructor; not traced */
    int unknown4c;   /* +0x4c: 1 from the constructor; not traced */
    float unknown50; /* +0x50: 1.0 from the constructor; not traced */
    float unknown54; /* +0x54: 1.0 from the constructor; not traced */
    float unknown58; /* +0x58: 1.0 from the constructor; not traced */
    int unknown5c;   /* +0x5c: 1 from the constructor; not traced */
    int unknown60;   /* +0x60: zero from the constructor; not traced */
    int unknown64;   /* +0x64: zero from the constructor; not traced */
    int unknown68;   /* +0x68: zero from the constructor; not traced */
    int unknown6c;   /* +0x6c: zero from the constructor; not traced */
    int unknown70;   /* +0x70: zero from the constructor; not traced */
    int unknown74;   /* +0x74: zero from the constructor; not traced */
    int unknown78;   /* +0x78: zero from the constructor; not traced */
    int unknown7c;   /* +0x7c: zero from the constructor; not traced */
    int unknown80;   /* +0x80: zero from the constructor; not traced */
    int unknown84;   /* +0x84: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_0139be10: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_0139bf00, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00b49c30.cpp)
 * emits the vtable and both destructors. */
inline Object016d0060::~Object016d0060() {}

#endif
