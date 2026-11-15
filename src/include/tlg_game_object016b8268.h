/* src/include/tlg_game_object016b8268.h: the class whose vtable is at
 * 0x16b8268 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8268_H
#define TLG_GAME_OBJECT016B8268_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b8268
 * (config/vtables.derived.base.txt, stored by FUN_00c1df90 FUN_013a2440
 * FUN_013a2530), derived from Object01343880: slot 5 overrides the
 * base's (FUN_00c1efc0), slot 9 is its own (FUN_00c1f060; declared, their
 * bodies are not members yet). 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00c1df90 sets them and its destructor FUN_013a2440
 * tears them down. */
class Object016b8268 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 24 bytes from +0x34
     * cleared (`vmovdqu [r15+0x34], xmm0; mov qword [r15+0x44], 0`: an int,
     * the two names, an int and two floats, a run of zero stores made one
     * memset), the four floats at +0x4c from the constants at 0x15437e0 (1, 0,
     * 0, 1) in one store, `mov dword [r15+0x5c], 0` */
    Object016b8268(const Name &name)
        : Object01343880(name), unknown34(0), unknown40(0), unknown44(0.0f), unknown48(0.0f),
          unknown4c(1.0f), unknown50(0.0f), unknown54(0.0f), unknown58(1.0f), unknown5c(0)
    {
    }

    virtual ~Object016b8268();
    /* slot 5, FUN_00c1efc0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();
    virtual void slot9(); /* derived name; FUN_00c1f060, not traced */

  private:
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    Name name38;     /* +0x38: empty from the constructor, released by the destructor */
    Name name3c;     /* +0x3c: empty from the constructor, released by the destructor */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    float unknown44; /* +0x44: zero from the constructor; not traced */
    float unknown48; /* +0x48: zero from the constructor; not traced */
    float unknown4c; /* +0x4c: 1.0 from the constructor; not traced */
    float unknown50; /* +0x50: zero from the constructor; not traced */
    float unknown54; /* +0x54: zero from the constructor; not traced */
    float unknown58; /* +0x58: 1.0 from the constructor; not traced */
    int unknown5c;   /* +0x5c: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_013a2440: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_013a2530, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00c1df90.cpp)
 * emits the vtable and both destructors. */
inline Object016b8268::~Object016b8268() {}

#endif
